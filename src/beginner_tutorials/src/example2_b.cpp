///函数功能：在同一个package下调用自定义的服务，直接#include就可以了
#include "ros/ros.h"
#include "beginner_tutorials/beginner_srv1.h"

int main(int argc,char** argv)
{
    ros::init(argc,argv,"example2_b");
    ros::NodeHandle n;
    ros::ServiceClient client=n.serviceClient<beginner_tutorials::beginner_srv1>("add_3_ints");
    beginner_tutorials::beginner_srv1 srv;
    srv.request.A=atoll(argv[1]);       //atoll将字符串转换为整型数
    srv.request.B=atoll(argv[2]);
    srv.request.C=atoll(argv[3]);
    if(client.call(srv))
    {
        ROS_INFO("Sum: %ld",(long int)srv.response.sum);
    }
    else
    {
        ROS_INFO("Failed to call service add_3_ints");
        return 1;
    }
    return 0;
}
