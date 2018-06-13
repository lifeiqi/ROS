///函数功能：动态参数
#include <ros/ros.h>
#include "dynamic_reconfigure/server.h"
#include "beginner_tutorials/beginner_Config.h"

void callback(beginner_tutorials::beginner_Config &config,uint32_t level)
{
    ROS_INFO("Reconfigure Request: %d %f %s %s %d",
             config.int_param,
             config.double_param,
             config.str_param.c_str(),
             config.bool_param ? "True":"False",
             config.size);
}

int main(int argc,char** argv)
{
    ros::init(argc,argv,"example4_dynamic_reconfigure");
    dynamic_reconfigure::Server<beginner_tutorials::beginner_Config> server;
    dynamic_reconfigure::Server<beginner_tutorials::beginner_Config>::CallbackType f;

    f=boost::bind(&callback,_1,_2);
    server.setCallback(f);
    //ROS_INFO("spinning node");

    ros::spin();
    return 0;
}
