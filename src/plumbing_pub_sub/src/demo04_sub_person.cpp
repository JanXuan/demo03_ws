#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h"
/*
    订阅方：订阅的消息
    1.包含头文件
    2.初始化Ros节点
    3.创建ROS节点句柄
    4.创建订阅者对象
    5.处理消息
    6.回调函数spin()
*/

void doPerson(const plumbing_pub_sub::Person::ConstPtr& person)
{
    ROS_INFO("订阅人信息:%s,%d,%.2f",person->name.c_str(),person->age,person->height);
}

int main(int argc, char *argv[])
{
    /* code */
    setlocale(LC_ALL,"");
    ROS_INFO("订阅方实现");
    //初始化Ros节点
    ros::init(argc,argv,"jiazhang");
    //创建ROS节点句柄
    ros::NodeHandle nh;
    //创建订阅者对象
    ros::Subscriber sub = nh.subscribe("liaotian",10,doPerson);
    //处理消息
    //回调函数spin()
    ros::spin();
    return 0;
}
