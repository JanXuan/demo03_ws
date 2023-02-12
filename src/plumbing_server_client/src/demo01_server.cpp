#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"
/*
    服务端实现：解析客户端提交的数据并运算产生响应
        1.包含相关头文件
        2.初始化ROS节点
        3.创建节点句柄
        4.创建服务对象
        5.处理请求并产生响应
        6.spin()
*/
//处理结果只有成功和失败，所以是返回bool类型
bool doNums(plumbing_server_client::AddInts::Request &request,
            plumbing_server_client::AddInts::Response &response)
{
    //1.处理请求
    int num1 = request.num1;
    int num2 = request.num2;
    ROS_INFO("收到请求的数据:num1=%d,num2=%d",num1,num2);
    //2.组织响应
    int sum = num1 + num2;
    response.sum = sum;
    ROS_INFO("求和的结果:sum=%d",sum);
    return true;
}

int main(int argc, char *argv[])
{
    /* code */
    setlocale(LC_ALL,"");
    //初始化ROS节点,名称保证唯一
    ros::init(argc,argv,"fuwu");
    //创建节点句柄
    ros::NodeHandle nh;
    //创建服务对象
    ros::ServiceServer server = nh.advertiseService("addInts",doNums);
    //处理请求并产生响应
    ROS_INFO("服务端启动");
    //spin()
    ros::spin();
    return 0;
}
