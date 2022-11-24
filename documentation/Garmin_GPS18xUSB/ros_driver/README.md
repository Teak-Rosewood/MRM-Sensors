# Garmin 18x USB interfacing using nmea-navsat-driver and an RPi
## Obtaining port number that garmin is connected to
Check tty files inside dev folder to look for currently used USB files.
```
$cd /dev
$ls
```
If unable to view dev file use root user to view.
```
$sudo su
$cd /dev
$ls
```
The required file will be named similar to:(0 may be any other value).
>/ttyUSB0

Read into all the files which match the USB file name(replace 0).
```
$sudo cat /dev/ttyUSB0
```
The required file will have output similar to:
>$GPGGA,090822,1320.8765,N,07447.5192,E,2,06,1.1,101.0,M,-88.1,M,,*69
>$GPGSA,A,3,10,13,15,24,25,29,,,,,,,1.4,1.1,0.9*33
>$GPGSV,3,1,11,10,30,267,14,13,17,044,14,15,51,049,25,24,21,130,23*72

The required port number is obtained.
## Install nmea-navstack-driver
Use the following command to install [NMEA Navstack Driver](http://wiki.ros.org/nmea_navsat_driver):
```
$sudo apt-get install ros-noetic-nmea-navsat-driver
```
To install from source code:
```
$git pull https://github.com/ros-drivers/nmea_navsat_driver
```
## Run the package
```
$rosrun nmea_navsat_driver nmea_serial_driver _port:=/dev/ttyUSB{port_name} _baud:=4800
```
## View on terminal
```
$rostopic echo /fix
```
