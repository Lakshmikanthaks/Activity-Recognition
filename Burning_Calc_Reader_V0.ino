// Example 52.4 PCF8591 ADC demo
// http://tronixstuff.com/tutorials Chapter 52
// John Boxall June 2013
#include "Wire.h"
#define PCF8591 (0x90 >> 1) // I2C bus address
byte value0, value1, value2, value3;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
  for (int id=0; id<8; id++) {
    int addr = (PCF8591 | id);
    Wire.beginTransmission(addr); // wake up PCF8591
    Wire.write(0x04); // control byte - read ADC0 then auto-increment
    Wire.endTransmission(); // end tranmission
    Wire.requestFrom(addr, 5);
    value0=Wire.read();
    value0=Wire.read();
    value1=Wire.read();
    value2=Wire.read();
    value3=Wire.read();
    Serial.print(value0);
    Serial.print("\t");
    Serial.print(value1);
    Serial.print("\t");
    Serial.print(value2);
    Serial.print("\t");
  }
  Serial.println();
  delay(20);
}



