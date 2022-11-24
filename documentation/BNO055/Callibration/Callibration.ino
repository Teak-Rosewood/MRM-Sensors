#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

Adafruit_BNO055 bno = Adafruit_BNO055(55);
  
void setup(void) 
{
  Serial.begin(9600);
  Serial.println("Callibration"); Serial.println("");
  
  // Initialise the sensor 
  
  if(!bno.begin(bno.OPERATION_MODE_NDOF_FMC_OFF))
  {
    // There was a problem detecting the BNO055 ... check your connections
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  delay(1000);
  
  bno.setExtCrystalUse(true);
}

void loop(void) 
{
  // Callibration 
  
  uint8_t offsets[22];
  uint8_t system, gyro, accel, mag;
  bno.getCalibration(&system, &gyro, &accel, &mag);
  bool a = bno.getSensorOffsets(&offsets[0]);

  // Accellerometer: 3 - Callibrated 0 - Not Callibrated (change planes slowly)
  // Gyrometer: 3 - Callibrated 0 - Not callibrated (keep stable for few seconds)
  // Magnetometer: 3 - Callibrated 0 - Not callibrated (sway and make 8s in the air)

  // Udipi - 242, 255, 1, 0, 229, 255, 40, 0, 184, 255, 224, 253, 255, 255, 0, 0, 0, 0, 232, 3, 188, 3
  
  Serial.print(accel);
  Serial.print(", ");
  Serial.print(gyro);
  Serial.print(", ");
  Serial.print(mag);
  Serial.print(", ");

  // Offset Values to be set
  
  Serial.print(offsets[0]);
  Serial.print(", ");
  Serial.print(offsets[1]);
  Serial.print(", ");
  Serial.print(offsets[2]);
  Serial.print(", ");
  Serial.print(offsets[3]);
  Serial.print(", ");
  Serial.print(offsets[4]);
  Serial.print(", ");
  Serial.print(offsets[5]);
  Serial.print(", ");
  Serial.print(offsets[6]);
  Serial.print(", ");
  Serial.print(offsets[7]);
  Serial.print(", ");
  Serial.print(offsets[8]);
  Serial.print(", ");
  Serial.print(offsets[9]);
  Serial.print(", ");
  Serial.print(offsets[10]);
  Serial.print(", ");
  Serial.print(offsets[11]);
  Serial.print(", ");
  Serial.print(offsets[12]);
  Serial.print(", ");
  Serial.print(offsets[13]);
  Serial.print(", ");
  Serial.print(offsets[14]);
  Serial.print(", ");
  Serial.print(offsets[15]);
  Serial.print(", ");
  Serial.print(offsets[16]);
  Serial.print(", ");
  Serial.print(offsets[17]);
  Serial.print(", ");
  Serial.print(offsets[18]);
  Serial.print(", ");
  Serial.print(offsets[19]);
  Serial.print(", ");
  Serial.print(offsets[20]);
  Serial.print(", ");
  Serial.print(offsets[21]);
  Serial.println("");
  
  delay(100);
}
