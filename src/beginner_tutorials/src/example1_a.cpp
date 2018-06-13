///函数功能：发布消息
#include "ros/ros.h"
#include "std_msgs/String.h"   //ros自带的消息类型
#include <sstream>   //c++中的标准数据类型，因此要用命名空间std::

int main(int argc,char** argv)
{
    ros::init(argc,argv,"example1_a");
    ros::NodeHandle n;
    ros::Publisher pub=n.advertise<std_msgs::String>("message",1000);
    ros::Rate loop_rate(10);

    int count=0;
    while(ros::ok())
    {
        std_msgs::String msg;
        std::stringstream ss;
        ss<<"I am the example1_a node "<<"["<<(++count)<<"]";
        msg.data=ss.str();
        ROS_INFO("%s",msg.data.c_str());
        pub.publish(msg);
        //ros::spinOnce();     //发送的时候可以不用spin或者spinOnce
        loop_rate.sleep();
    }
    return 0;
}




//API（Application Programming Interface,应用程序编程接口）是一些预先定义的函数
//目的是提供应用程序与开发人员基于某软件或硬件得以访问一组例程的能力，而又无需访问源码，或理解内部工作机制的细节

//argc, argv是用来解析来自命令行remapping arguments, 而所谓remapping arguments就是在调用
//rosrun package_name node_name param_name:=param_value 中的 param:=param_value 部分

//str是std::ostringstream的对象，用起来和cout差不多，都可以使用<<运算符，将数字和字符串“流出”
//不同的是cout将内容流出到控制台窗口，而std::ostringstream将内容流入到内部的字符串(std::string)内，可以使用成员函数str()获取流入的内容

//c_str()函数返回一个指向正规C字符串的指针,内容与本string串相同.这是为了与c语言兼容
//在c语言中没有string类型，故必须通过string类对象的成员函数c_str()把string对象转换成c中的字符串样式

//add_executable 命令
//命令语法：add_executable(<name> [WIN32] [MACOSX_BUNDLE][EXCLUDE_FROM_ALL] source1 source2 … sourceN)
//命令简述：用于指定从一组源文件 source1 source2 … sourceN 编译出一个可执行文件且命名为 name
