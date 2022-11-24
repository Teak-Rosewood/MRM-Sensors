# BNO055 - Sensor data 

## Prerequisites 
 
1. [Arudino IDE](https://www.arduino.cc/en/software)
2. [Data Sheet](https://pdf1.alldatasheet.com/datasheet-pdf/view/1132074/BOSCH/BNO055.html)
3. Cloning of this repository 
4. The libraries included are added  
5. Permissions for uplading code on Audrino 
```
sudo chmod a+rw /dev/ttyACM0
```

## Callibration 
 
Open the Callibration file in the directory and run the code
1. The first three values of the CSV indicate the callibration status of the 3 Sensors
2. Once all 3 Sensors show a 3 on their callibration Note down the offset Values

## Working 

Open the Working file and run the code on the Arudino
1. Set the Offsets to the callibratd values in the code 
2. Run the code
3. The acceleration in x, y ,z and the Roll, Pitch and Yaw data is displayed in CSV format