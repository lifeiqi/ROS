///函数功能：在同一个package下调用自定义的服务，直接#include就可以了
#include "ros/ros.h"
#include "beginner_tutorials/beginner_srv1.h"

bool add(beginner_tutorials::beginner_srv1::Request &req,
        beginner_tutorials::beginner_srv1::Response &res)
{
    res.sum=req.A+req.B+req.C;
    ROS_INFO("request:A=%ld,B=%ld,C=%ld",(int)req.A,(int)req.B,(int)req.C);
    ROS_INFO("sending back response: [%ld]",(int)res.sum);
    return true;
}

int main(int argc,char** argv)
{
    ros::init(argc,argv,"example2_a");
    ros::NodeHandle n;
    ros::ServiceServer service=n.advertiseService("add_3_ints",add);
    ROS_INFO("Ready to add 3 ints.");
    ros::spin();

    return 0;
}