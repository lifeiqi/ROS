///函数功能：在同一个package下调用自定义的消息，直接#include就可以了
#include "ros/ros.h"
#include "beginner_tutorials/beginner_msg1.h"

void messageCallback(const beginner_tutorials::beginner_msg1::ConstPtr &msg)
{
    ROS_INFO("I heard: [%d] [%d] [%d]",msg->A,msg->B,msg->C);
}

int main(int argc,char** argv)
{
    ros::init(argc,argv,"example3_b");
    ros::NodeHandle n;
    ros::Subscriber sub=n.subscribe("message",1000,messageCallback);
    ros::spin();     //spin的话有数据过来就会回调？多长时间轮寻一次？不需要设置时间间隔？
    return 0;
}

//add_dependencies(example3_b beginner_tutorials_generate_messages_cpp)
//add_dependencies还是要加的，要不然很可能会找不到自定义消息生成的头文件