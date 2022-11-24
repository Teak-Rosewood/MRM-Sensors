#!/usr/bin/env python3
import serial
from sensor_msgs.msg import NavSatFix
from ublox_gps import UbloxGps
import rospy
import sys
rospy.init_node('GPS', anonymous=True)
pub = rospy.Publisher('/fix', NavSatFix, queue_size=10)
port = serial.Serial('/dev/ttyACM0', baudrate=38400, timeout=0.1)
gps = UbloxGps(port)

def run():

    try:
        print("Listening for UBX Messages")
        rtk = NavSatFix()
        while not rospy.is_shutdown():
            try:
                geo = gps.geo_coords()
                rtk.longitude = geo.lon

                rtk.latitude = geo.lat
            except (ValueError, IOError) as err:
                print(err)
            except KeyboardInterrupt:
                break
            pub.publish(rtk)

    finally:
        port.close()


if __name__ == '__main__':
    try:
        run()
    except KeyboardInterrupt:
        sys.exit(0)
