#include "ros/ros.h"
#include "std_msgs/String.h"
/*          
            话题通信订阅方源代码
    步骤：
        1.包含头文件此为ros.h与String.h
            ROS中的文本类型头文件-->>std_msgs/String.h
        2.初始化ros节点
        3.创建节点句柄
        4.创建订阅者对象
        5.处理订阅数据
        6.声明一个spin()函数
*/
void doMsg(const std_msgs::String::ConstPtr &msg)
{   //通过msg获取并操作订阅的数据
    ROS_INFO("订阅方订阅的数据：%s",msg->data.c_str());
}

int main(int argc, char *argv[])
{
    /* code */
    setlocale(LC_ALL,"");
    //初始化ros节点
    ros::init(argc,argv,"Sub");
    //创建节点句柄
    ros::NodeHandle nh;
    //创建订阅者对象
    ros::Subscriber sub = nh.subscribe("huati",10,doMsg);
    //处理订阅数据

    ros::spin();
    //用于回头回调使得doMsg函数重复使用每订阅一条数据就回调doMsg一次
    //回调函数只有当msg传入时才立即回头执行类似QT信号槽和中断
    return 0;
}
