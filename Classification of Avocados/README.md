### Use:
* Install: https://github.com/code-iai/iai_kinect2
* Remove sudo permissions: https://github.com/OpenKinect/libfreenect2/issues/79
* Create a ROS WS: http://wiki.ros.org/ROS/Tutorials/InstallingandConfiguringROSEnvironment
* For RVIZ and Bridge: roslaunch .... publish_tf:=true


## Save data
* sudo apt-get update
* sudo apt-get install ros-kinetic-pcl-conversions
* sudo apt-get install ros-kinetic-pcl-ros
* Install: my_pack (using catkin)
* Download the my_pack folder and paste it into the path: catkin_ws/src
* Go to the catkin_ws path and make a catkin_make
* In path catkin_ws, make a catkin_make install
* Run the thread and bridge normally
* Running in the catkin_ws path the line: source devel/setup.bash
* Run: rosrun my_pack k2_capture {here goes the path and file name with extension.txt}, example: rosrun my_pack k2_capture /home/harold/Escritorio/data.txt
* Modify the capture.cpp file in the my_pack/src/ directory to change the limits of the Kinect capture area, as well as change the grayscale value to detect avocados.

## view data in MATLAB
*  run Calibracion.m in Matlab
