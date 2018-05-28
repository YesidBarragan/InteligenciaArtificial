#include <ros/ros.h>
// PCL specific includes
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include "SimpleSerial.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace boost;
using namespace std;
ofstream myfile;

std::string first_arg;
std::string fileName;
ros::Publisher pub;

int cont=0;
void
cloud_cb (const sensor_msgs::PointCloud2ConstPtr& input)
{

  myfile.open(fileName.c_str());
  //myfile << "NODE\t" << "X\t" << "Y\t" << "Z\t" << "R\t" << "G\t" << "B\n";
  float x = 0, y = 0, z=0; // set x and y
  int R=0, G=0, B=0;
  pcl::PointCloud<pcl::PointXYZRGB> depth;
  pcl::fromROSMsg( *input, depth);
  int width = depth.width;
  int height = depth.height;
  int L = depth.points.size();
  int gri=0;
  cont=0;
  for (size_t i =0; i < L; i++){
    x = depth.points[i].x;
    z = -depth.points[i].y;
    y = depth.points[i].z;
    R = depth.points[i].r;
    G = depth.points[i].g;
    B = depth.points[i].b;
    gri=(R+G+B)/3;
    if (y<1 && z<0.15 && z>-0.15 && x<0.1 && x>-0.1){
      if(gri>155){
          myfile << x << "\t" << y << "\t" << z << "\t" << R << "\t" << G << "\t" << B << "\n";
          cont++;
      }

    }

  /*  printf ( "x: %f\t",x );
    printf ( "y: %f\t",y );
    printf ( "z: %f\t",z );
    printf ( "R: %d\t",R );
    printf ( "G: %d\t",G );
    printf ( "B: %d\n",B );
    */
  }
  myfile.close();
  ros::shutdown();
  //sensor_msgs::PointCloud2 output;
  // Publish the map
  //output = *input;
  //pub.publish(output);
   // ---------------------------------
  // Perform the actual filtering
  //pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
  //sor.setInputCloud (cloudPtr);
  //sor.setLeafSize (0.1, 0.1, 0.1);
  //sor.filter (cloud_filtered);

  // Convert to ROS data type
  //sensor_msgs::PointCloud2 output;
  //pcl_conversions::moveFromPCL(cloud_filtered, output);

  // Publish the data
  //pub.publish (output);
}
void delay(int secs) {
  for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}

int
main (int argc, char* argv[])
{
  // Initialize ROS

//*  printf("%s\n", fileName.c_str() );
  printf("%s\n", "asdgasdgasdg");
  // Create a ROS publisher for the output point cloud
  try {

  SimpleSerial serial("/dev/ttyACM0",9600);
  //serial.writeString("1\n");
  while(1){
        ros::init (argc, argv, "k2_capture");
        ros::NodeHandle nh;
        // Create a ROS subscriber for the input point cloud
        uint32_t queue_size = 1;

        first_arg= argv[1];
        fileName = first_arg;
          ros::Subscriber sub = nh.subscribe<sensor_msgs::PointCloud2> ("/kinect2/sd/points", queue_size, cloud_cb);
    pub = nh.advertise<sensor_msgs::PointCloud2> ("output", 1);
    // Spin
    ros::spin();
  printf ( "tamano: %d\n",cont );
    return 0;//para calibrar

      if(cont<900 && cont>800){
          printf("%s\n", "DETECTO, DETENER");
        serial.writeString("0\n");
        delay(5);
      }
      serial.writeString("1\n");
          //  printf("%s\n", "CONTINUAR");
  }

} catch(boost::system::system_error& e)
 {
     cout<<"Error: "<<e.what()<<endl;
     return 1;
 }
  return 0;
}
