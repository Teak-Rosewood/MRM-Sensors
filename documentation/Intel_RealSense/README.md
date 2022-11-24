# Intel RealSense Stereocam

## Connections 
USB C -  output <br/>
USB A - input

## Camera Interfacing
OpenCV2 video capture

## CV Image to ROS Image
cv_bridge

## Publishing Topic
/Image

## Publishing Message
sensor_msgs/Image.msg

## Setup for RViz Visualisation
### Raspberry Pi
1. Set ```ROS_MASTER_URI=http://xxx.xxx.xxx.xxx:11311```
2. Set ```ROS_IP=xxx.xxx.xxx.xxx```
3. Run the following lines of code:
   ```
   cd ~/catkin_ws
   catkin_make
   source devel/setup.bash
   rosrun realsense realsense.py
   ```

### Visulisation Station
1. Set ```ROS_MASTER_URI=http://xxx.xxx.xxx.xxx:11311```
2. Set ```ROS_IP=xxx.xxx.xxx.xxx```
3. Open RViz
4. Add Image
5. Set topic /Image

#### ```roscore``` needs to be running on the master address before executing realsense.py
