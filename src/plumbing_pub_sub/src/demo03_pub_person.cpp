#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h"

/*
    发布方：发布人的消息
    1.包含头文件
    2.初始化Ros节点
    3.创建ROS节点句柄
    4.创建发布者对象
    5.编写发布逻辑发布数据
*/

int main(int argc, char *argv[])
{
    /* code */
    setlocale(LC_ALL,"");
    ROS_INFO("这是发布方");
    //初始化Ros节点
    ros::init(argc,argv,"banzhuren");
    //创建ROS节点句柄
    ros::NodeHandle nh;
    //创建发布者对象
    ros::Publisher pub = nh.advertise<plumbing_pub_sub::Person>("liaotian",10);
    //编写发布逻辑发布数据
    //创建被发布的数据
    plumbing_pub_sub::Person person;
    person.name = "张三";
    person.age = 1;
    person.height = 1.73;
    //设置发布频率
    ros::Rate rate(1);
    //循环发布
    while(ros::ok())
    {
        //修改被发布的数据
        person.age += 1;
        //发布数据
        pub.publish(person);
        ROS_INFO("发布消息:%s,%d,%.2f",person.name.c_str(),person.age,person.height);
        rate.sleep();
        //建议
        ros::spinOnce();
    }
    return 0;
}
