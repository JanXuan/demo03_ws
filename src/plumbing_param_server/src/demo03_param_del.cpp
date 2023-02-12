#include "ros/ros.h"

/*
    演示参数的删除：
        实现：
            ros::NodeHandle
                            deleteParam()
            ros::param
                            del()
*/

int main(int argc, char *argv[])
{
    /* code */
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"param_del_c");
    ros::NodeHandle nh;
    //删除：NodeHandle
    bool flag1 = nh.deleteParam("radius");
    if(flag1)
    {
        ROS_INFO("radius删除成功");
    }
    else
    {
        ROS_INFO("radius删除失败");
    }
    //删除：ros::param
    bool flag2 = ros::param::del("radius_param");
    if(flag1)
    {
        ROS_INFO("radius_param删除成功");
    }
    else
    {
        ROS_INFO("radius_param删除失败");
    }
    return 0;
}
