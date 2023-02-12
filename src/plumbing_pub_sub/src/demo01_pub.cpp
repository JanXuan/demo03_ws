#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>//字符串拼接头文件
/*          
            话题通信发布方源代码
    步骤：
        1.包含头文件此为ros.h与String.h
            ROS中的文本类型头文件-->>std_msgs/String.h
        2.初始化ros节点
        3.创建节点句柄
        4.创建发布者对象
        5.发布数据
*/

int main(int argc, char *argv[])
{
    /* code */
    setlocale(LC_ALL,"");
    //初始化ros节点
    ros::init(argc,argv,"Pub");
    //创建节点句柄
    ros::NodeHandle nh;
    //创建发布者对象发布对象在Publisher里，用句柄的advertise函数,advertise<泛型>("话题名"，队列/缓存区长度)
    ros::Publisher pub = nh.advertise<std_msgs::String>("huati",10);
    //发布数据以1s10次发送消息
    //先创建发布消息而后循环发布
    std_msgs::String msg;
    ros::Rate rate(10);
    int count = 0;
    //调用Rate函数构造rate对象，参数为10HZ
    ros::Duration(3).sleep();
    //休眠三秒使得订阅方先挂起状态下，等待发布方注册完
    while (ros::ok())//节点未关闭则一直循环
    {
        /* code */
        count++;
        //msg.data="hello ros";
        //消息对象msg中赋值字符串
        std::stringstream ss;
        //创建字符串拼接对象ss
        ss<<"hello -->"<<count;
        //使用流操作符赋值给ss
        msg.data = ss.str();
        pub.publish(msg);
        //添加日志输出
        ROS_INFO("发布的数据是：%s",ss.str().c_str());
        //调用发布者对象pub里的消息发布函数，发布消息msg
        rate.sleep();//上面设置rate对象参数为10HZ,调用其sleep函数即可1s10次
        ros::spinOnce();//官方建议
    }
    
    return 0;
}
