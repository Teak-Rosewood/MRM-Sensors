#include <ros/ros.h>
#include <string>
#include "sensor_msgs/LaserScan.h"

class Scan
{
    public:
        Scan();

    private:
        void LaserCallback(const sensor_msgs::LaserScan::ConstPtr &las);
        void splitter();
        sensor_msgs::LaserScan laser;
        std::string frame;
        ros::NodeHandle n;
        ros::Subscriber sub;
        ros::Publisher pub1;
        ros::Publisher pub2;
        ros::Publisher pub3;
        ros::Publisher pub4;
        ros::Publisher pub5;
        ros::Publisher pub6;
        ros::Publisher pub7;
        ros::Publisher pub8;
        ros::Publisher pub9;
        ros::Publisher pub10;
        ros::Publisher pub11;
        ros::Publisher pub12;
};

void Scan::LaserCallback(const sensor_msgs::LaserScan::ConstPtr &las)
{
    laser = *las;
    frame = laser.header.frame_id;
    splitter();
}

void Scan::splitter()
{
    if(frame.find("NEG_500_DIST1")!=std::string::npos)
    {
        laser.header.frame_id = "MRS1000_NEG_500_1";
        pub1.publish(laser);
    }
    else if(frame.find("NEG_500_DIST2")!=std::string::npos)
    {
        laser.header.frame_id = "MRS1000_NEG_500_2";
        pub2.publish(laser);
    }
    else if(frame.find("NEG_500_DIST3")!=std::string::npos)
    {
        laser.header.frame_id = "MRS1000_NEG_500_3";
        pub3.publish(laser);        
    }
    else if(frame.find("NEG_250_DIST1")!=std::string::npos)
    {
        laser.header.frame_id = "MRS1000_NEG_250_1";
        pub4.publish(laser);       
    }
    else if(frame.find("NEG_250_DIST2")!=std::string::npos)
    {
        laser.header.frame_id = "MRS1000_NEG_250_2";
        pub5.publish(laser);        
    }
    else if(frame.find("NEG_250_DIST3")!=std::string::npos)
    {
        laser.header.frame_id = "MRS1000_NEG_250_3";
        pub6.publish(laser);        
    }
    else if(frame.find("POS_000_DIST1")!=std::string::npos)
    {
        laser.header.frame_id = "MRS1000_POS_000_1";
        pub7.publish(laser);        
    }
    else if(frame.find("POS_000_DIST2")!=std::string::npos)
    {
        laser.header.frame_id = "MRS1000_POS_000_2";
        pub8.publish(laser);        
    }
    else if(frame.find("POS_000_DIST3")!=std::string::npos)
    {
        laser.header.frame_id = "MRS1000_POS_000_3";
        pub9.publish(laser);        
    }
    else if(frame.find("POS_250_DIST1")!=std::string::npos)
    {
        laser.header.frame_id = "MRS1000_POS_250_1";
        pub10.publish(laser);
    }
    else if(frame.find("POS_250_DIST2")!=std::string::npos)
    {
        laser.header.frame_id = "MRS1000_POS_250_2";
        pub11.publish(laser);
    }
    else if(frame.find("POS_250_DIST3")!=std::string::npos)
    {
        laser.header.frame_id = "MRS1000_POS_250_3";
        pub12.publish(laser);
    }
    else
    {
        ROS_INFO("What the fuck");
    }
}
Scan::Scan()
{
    sub = n.subscribe<sensor_msgs::LaserScan>("scan",10,&Scan::LaserCallback,this);
    pub1 = n.advertise<sensor_msgs::LaserScan>("scan_-500",10);
    pub2 = n.advertise<sensor_msgs::LaserScan>("scan_NEG500_1",10);
    pub3 = n.advertise<sensor_msgs::LaserScan>("scan_NEG500_2",10);
    pub4 = n.advertise<sensor_msgs::LaserScan>("scan_-250",10);
    pub5 = n.advertise<sensor_msgs::LaserScan>("scan_NEG250_1",10);
    pub6 = n.advertise<sensor_msgs::LaserScan>("scan_NEG250_2",10);
    pub7 = n.advertise<sensor_msgs::LaserScan>("scan_000",10);
    pub8 = n.advertise<sensor_msgs::LaserScan>("scan_POS_000_1",10);
    pub9 = n.advertise<sensor_msgs::LaserScan>("scan_POS_000_2",10);
    pub10 = n.advertise<sensor_msgs::LaserScan>("scan_250",10);
    pub11 = n.advertise<sensor_msgs::LaserScan>("scan_POS_250_1",10);
    pub12 = n.advertise<sensor_msgs::LaserScan>("scan_POS_250_2",10);
    ros::spin();
}
int main(int argc,char** argv){
    ros::init(argc,argv,"scan_node");
    Scan sc;
}
