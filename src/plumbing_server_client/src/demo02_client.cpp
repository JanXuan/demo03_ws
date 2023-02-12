#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"
/*
    客户端：提交两个整数并处理响应结果
        1.包含相关头文件
        2.初始化ROS节点
        3.创建节点句柄
        4.创建客户端对象
        5.提交请求并处理响应
    实现参数的动态提交：
        1.格式： rosrun xxxxx(包名) xxxxx(节点名称) 12(参数1) 34(参数2)
        2.节点执行时需要获取命令中的参数并组织进request(用argc,argv实现)
    客户端先启动实现：
        可以先挂起，等服务器启动后再正常请求
        因为一般实际开发中会有许多节点，节点的启动不能保证顺序，难免有请求响应关系
    解决：
        在ROS中内置了相关函数，客户端挂起等待服务器启动
        函数1如果服务器没启动就挂起，等服务器启动
            client.waitForExistence();
        函数2,一直等待话题为"addInts"的服务
            ros::service::waitForService("addInts");
*/
//argc表示传入参数数量，第一个是程序名，第二个是12(参数1),第三个是34(参数2)所以argc=3
//argv即上面的三个参数
int main(int argc, char *argv[])
{
    /* code */
    //优化实现，获取命令中的参数
    if(argc != 3)
    {
        ROS_INFO("提交参数个数不对！");
        return 1;
    }
    setlocale(LC_ALL,"");
    //初始化ROS节点
    ros::init(argc,argv,"kehu");
    //创建节点句柄
    ros::NodeHandle nh;
    //创建客户端对象
    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::AddInts>("addInts");
    //提交请求并处理响应
    plumbing_server_client::AddInts ai;
    //组织请求
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);
    //处理响应
    //判断服务器状态函数
    //函数1如果服务器没启动就挂起，等服务器启动
    client.waitForExistence();
    //函数2,一直等待话题为"addInts"的服务
    //ros::service::waitForService("addInts");
    bool flag = client.call(ai);
    if(flag)
    {
        ROS_INFO("响应成功！");
        //获取结果
        ROS_INFO("响应结果=%d",ai.response.sum);
    }
    else
    {
        ROS_INFO("处理失败！");
    }
    return 0;
}
