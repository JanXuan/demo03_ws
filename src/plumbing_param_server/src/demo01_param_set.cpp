#include "ros/ros.h"

/*
    实现参数的新增和修改
    需求：
        设置机器人的共享参数，类型，半径(0.15m)
        再修改半径(0.2m)
    实现：
        ros::NodeHandle
            setParam("键"，值)
        ros::param
            set("键"，值)
    修改只需要继续调用set函数保证键不变就行
*/

int main(int argc, char *argv[])
{
    /* code */

    //初始化ROS节点
    ros::init(argc,argv,"set_param_c");
    //创建节点句柄
    ros::NodeHandle nh;
    //参数新增
    //方案1：nh.setParam(参数名字，参数值(很多类型))
    nh.setParam("type","xiaohuang");//机器人名小黄
    nh.setParam("radius",0.15);//半径0.15
    //方案2：ros::param
    ros::param::set("type_param","xiaobai");
    ros::param::set("radius_param",0.15);
    //参数修改
    //方案1：nh
    nh.setParam("radius",0.2);
    //方案2：ros::param
    ros::param::set("radius_param",0.25);
    return 0;
}
