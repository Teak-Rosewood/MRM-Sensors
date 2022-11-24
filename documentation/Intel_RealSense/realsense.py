#!/usr/bin/python3

"""This module access camera using OpenCV and Publishes it on the /Image ROS topic"""

from webbrowser import get
import cv2 as cv
import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
def getImage(camera_index:int = 4):
    cap = cv.VideoCapture(camera_index)
    pub = rospy.Publisher('/image', Image,queue_size=100)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(100)
    while(not rospy.is_shutdown()):
        ret, frame = cap.read()
        bridge = CvBridge()
        image_message = bridge.cv2_to_imgmsg(frame, encoding="passthrough")
        pub.publish(image_message)
        print('published')
    cap.release()
    print('exiting...')

if __name__=='main':
    getImage()
