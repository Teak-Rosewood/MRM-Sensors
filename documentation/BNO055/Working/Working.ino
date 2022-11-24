#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

Adafruit_BNO055 bno = Adafruit_BNO055(55);

void setup(void) 
{
  // boud rate = 9600
  
  Serial.begin(9600);
  Serial.println("Setting up BNO055"); Serial.println("");
  
  /* Initialise the sensor */
  
  if(!bno.begin(bno.OPERATION_MODE_NDOF_FMC_OFF))
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  // Setting offsets 
  
  uint8_t offsets[22];
  offsets[0] = 242;
  offsets[1] = 255;
  offsets[2] = 1;
  offsets[3] = 0;
  offsets[4] = 229;
  offsets[5] = 255;
  offsets[6] = 40;
  offsets[7] = 0;
  offsets[8] = 184;
  offsets[9] = 255;
  offsets[10] = 224;
  offsets[11] = 253;
  offsets[12] = 255;
  offsets[13] = 255;
  offsets[14] = 0;
  offsets[15] = 0;
  offsets[16] = 0;
  offsets[17] = 0;
  offsets[18] = 232;
  offsets[19] = 3;
  offsets[20] = 188;
  offsets[21] = 3;
  
  bno.setSensorOffsets(&offsets[0]);
  delay(1000);
  
  bno.setExtCrystalUse(true);

}

void loop() {
  
  // Get a new sensor event 
  
  sensors_event_t event_orientation; 
  sensors_event_t event_acceleration;
  bno.getEvent(&event_acceleration,Adafruit_BNO055::VECTOR_ACCELEROMETER);
  bno.getEvent(&event_orientation,Adafruit_BNO055::VECTOR_EULER);

  
  // ax, ay, az, roll, pitch, yaw 
  
  
  Serial.print(event_acceleration.acceleration.x, 4);
  Serial.print(", ");
  Serial.print(event_acceleration.acceleration.y, 4);
  Serial.print(", ");
  Serial.print(event_acceleration.acceleration.z, 4);
  Serial.print(", ");
  Serial.print(event_orientation.orientation.x, 4);
  Serial.print(", ");
  Serial.print(event_orientation.orientation.y, 4);
  Serial.print(", ");
  Serial.print(event_orientation.orientation.z, 4);
  Serial.println(""); 
}
