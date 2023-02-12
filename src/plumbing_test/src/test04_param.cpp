#include "ros/ros.h"

/*
    需求：修改参数服务器中turtlesim背景色相关参赛
        1.初始化ROS节点
        2.不一定需要创建节点句柄
        3.修改参数
*/
/*

*/
int main(int argc, char *argv[])
{
    /* code */
    //1.初始化ROS节点
    ros::init(argc,argv,"change_bgColor");
    //2.不一定需要创建节点句柄
    //方式1
    //ros::NodeHandle nh("turtlesim");
    //nh.setParam("background_r",255);//nh会自己组合成/turtlesim/background_r
    //nh.setParam("background_g",255);
    //nh.setParam("background_b",255);
    //方式2
    ros::NodeHandle nh;
    nh.setParam("/turtlesim/background_r",0);
    nh.setParam("/turtlesim/background_g",50);
    nh.setParam("/turtlesim/background_b",100);
    //3.修改参数
    //方式3
    //如果调用ros::param不需要创建节点句柄
    //ros::param::set("/turtlesim/background_r",0);
    //ros::param::set("/turtlesim/background_g",0);
    //ros::param::set("/turtlesim/background_b",0);
    return 0;
}
