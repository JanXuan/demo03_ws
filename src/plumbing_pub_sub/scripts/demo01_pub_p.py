#! /usr/bin/env/python

import rospy
from std_msgs import String #发布消息类型
"""
    使用python实现消息发布:
        1.导包
        2.初始化ROS节点
        3.创建发布者对象
        4.编写发布逻辑发布数据
"""
if __name__ == "__main__":
    #初始化ROS节点
    rospy.init_node("sanDai")   #传入节点名称
    #创建发布者对象
    pub = rospy.Publisher("che",String,queue_size=10)
    #编写发布逻辑发布数据
    #创建数据
    msg = String()
    #使用循环发布数据
    while not rospy.is_shutdown():
        msg.data = "hello"
        pub.publish(msg)
    