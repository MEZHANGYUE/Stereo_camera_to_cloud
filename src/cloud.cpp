#include "cloud.h"
 #include <cmath>
 
struct EulerAngles {
    double roll, pitch, yaw;
};

subscriberANDpublisher::subscriberANDpublisher()
{
    
    //订阅话题
    image_left.subscribe(nh, "/iris/stereo_camera/left/image_raw", 10);
    image_right.subscribe(nh, "/iris/stereo_camera/left/image_raw", 10);
 
    //回调
    sync_.reset(new Sync(syncpolicy(10), image_left, image_right));
    sync_->registerCallback(boost::bind(&subscriberANDpublisher::callback, this, _1, _2));
    ROS_INFO("init done!");
}
void subscriberANDpublisher::callback(const sensor_msgs::Image::ConstPtr &left,  const sensor_msgs::Image::ConstPtr &right)   //数据处理
{
    ROS_INFO("done! ");
	
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "cloud");
    subscriberANDpublisher sp;
    ROS_INFO("main done! ");
    ros::spin();
 
}