////////////////////////////////////////////////////////////////////////
/// Copyright (c)2015 Dan Truong
/// Permission is granted to use this software under the MIT
/// licence, with my name and copyright kept in source code
/// http://http://opensource.org/licenses/MIT
///
/// KY039 Arduino Heartrate Monitor V1.0 (April 02, 2015)
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
/// @param[in] IRSensorPin Analog pin on which IR detector is connected
/// @param[in] delay (msec) delay between calls to this method. It is
///                  best to call it at least 5 times per beat, aka
///                  no slower than 150msec for 70bpm. An ideal value
///                  is 60ms or faster to handle up to 200 BPM.
///
/// @brief
/// True if heartbeat is detected on the sensor.
/// This code is trivial and just does a peak detection, instead of
/// trying to detect the heart's pulse waveform.
/// Note: I am fudging sensor data with the delay to make the integer
/// math after that uses constants, somewhat independant of the sleep
/// delay used in the main loop. Otherwise if maxValue decays too slow
/// or too fast, it causes glitches and false beat detection.
////////////////////////////////////////////////////////////////////////
//#define HBDEBUG(i) i
#define HBDEBUG(i)

#include <DHT11.h>
#include<Wire.h>
const int delayMsec =40; 
int analogPin=0;
const int MPU=0x68;
int pin=4;
int16_t AcX,AcY,AcZ,GyX,GyY,GyZ;
int16_t AcX_old, AcY_old, AcZ_old;
DHT11 dht11(pin); 

bool heartbeatDetected(int IRSensorPin, int delay)
{
  static int maxValue = 0;
  static bool isPeak = false;
  int rawValue;
  bool result = false;
    
  rawValue = analogRead(IRSensorPin);
  // Separated because analogRead() may not return an int
  rawValue *= (1000/delay);
  HBDEBUG(Serial.print(isPeak); Serial.print("p, "));
  HBDEBUG(Serial.print(rawValue); Serial.print("r, "));
  HBDEBUG(Serial.print(maxValue); Serial.print("m, "));

  // If sensor shifts, then max is out of whack.
  // Just reset max to a new baseline.
  if (rawValue * 4L < maxValue) {
    maxValue = rawValue * 0.8;
    HBDEBUG(Serial.print("RESET, "));
  }
  
   if (rawValue > maxValue - (1000/delay)) {
    // Only change peak if we find a higher one.
    if (rawValue > maxValue) {
      maxValue = rawValue;
    }
    // Only return true once per peak.
    if (isPeak == false) {
      result = true;
    }
    isPeak = true;
  } else if (rawValue < maxValue - (3000/delay)) {
    isPeak = false;
    // Decay max value to adjust to sensor shifting
    // Note that it may take a few seconds to re-detect
    // the signal when sensor is pushed on meatier part
    // of the finger. Another way would be to track how
    // long since last beat, and if over 1sec, reset
    // maxValue, or to use derivatives to remove DC bias.
    maxValue-=(1000/delay);
 }
  HBDEBUG(Serial.print("\n"));
  return result;
}


void setup(void)
{
  Serial.begin(115200);             
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);    
}

void loop(void)
{
  int err;
  float temp, humi;
  float vx,vy,vz,velocity;
  static int beatMsec = 0;
  int heartRateBPM = 0;
  
  if (heartbeatDetected(analogPin, delayMsec)) 
  {
    Wire.beginTransmission(MPU);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU,14,true);
    AcX_old=Wire.read()<<8|Wire.read();
    AcY_old=Wire.read()<<8|Wire.read();
    AcZ_old=Wire.read()<<8|Wire.read();
    delay(50);
    
    heartRateBPM = 20000 / beatMsec;
    Wire.beginTransmission(MPU);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU,14,true);
    AcX=Wire.read()<<8|Wire.read();
    AcY=Wire.read()<<8|Wire.read();
    AcZ=Wire.read()<<8|Wire.read();
    vx=(float)((abs(AcX-AcX_old)/(float)16384)*9.8*0.05);
    vy=(float)((abs(AcY-AcY_old)/(float)16384)*9.8*0.05);
    vz=(float)((abs(AcZ-AcZ_old)/(float)16384)*9.8*0.05);
    velocity=sqrt((vx*vx)+(vy*vy)+(vz*vz));
    if(((err=dht11.read(humi, temp))==0) && heartRateBPM>0 )
    {
        //Serial.println(heartRateBPM);
        Serial.print(heartRateBPM/3);
        Serial.print(" ");
        Serial.print((int)(temp+0.5f));
        Serial.print(" ");
        Serial.print((int)(velocity*3.6f));  //km/h
        Serial.print(" ");
        Serial.println(heartRateBPM%3);  
        beatMsec = 0;
        delay(1950);
    }
  }
  delay(delayMsec);
  beatMsec += (delayMsec);
}





