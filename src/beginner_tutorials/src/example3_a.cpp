///函数功能：在同一个package下调用自定义的消息，直接#include就可以了
#include "ros/ros.h"
#include "beginner_tutorials/beginner_msg1.h"

int main(int argc,char** argv)
{
    ros::init(argc,argv,"example3_a");
    ros::NodeHandle n;
    ros::Publisher pub=n.advertise<beginner_tutorials::beginner_msg1>("message",1000);
    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        beginner_tutorials::beginner_msg1 msg;
        msg.A=1;
        msg.B=2;
        msg.C=3;
        pub.publish(msg);
        //ros::spinOnce();       //pub的话其实可以不用spin或者spinOnce
        loop_rate.sleep();
    }
    return 0;
}

