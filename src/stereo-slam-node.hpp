// STL
#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <queue>
// ROS
#include <rclcpp/rclcpp.hpp>
#include "sensor_msgs/msg/image.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include <cv_bridge/cv_bridge.h>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
// Opencv
#include <opencv2/core/core.hpp>
// ORB-SLAM
#include "/home/conti/ORB_SLAM3/include/System.h"

//class ImuGrabber
//{
//public:
//    ImuGrabber(){};
//    void GrabImu(const sensor_msgs::ImuConstPtr &imu_msg);
//
//    std::queue<sensor_msgs::msg::SharedPtr> imuBuf;
//    std::mutex mBufMutex;
//};

class StereoSlamNode : public rclcpp::Node
{
    public:
        StereoSlamNode(ORB_SLAM3::System* pSLAM, const string &strSettingsFile, const string &strDoRectify);

        ~StereoSlamNode();
    private:
         
        using ImageMsg = sensor_msgs::msg::Image;
        using ImuMsg = sensor_msgs::msg::Imu;
        typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::msg::Image, sensor_msgs::msg::Image> approximate_sync_policy;

        void GrabStereo(const sensor_msgs::msg::Image::SharedPtr msgRGB, const sensor_msgs::msg::Image::SharedPtr msgD);
        void SyncWithImu();

        //void GrabImu(const sensor_msgs::msg::Imu::SharedPtr &imu_msg);
        

        ORB_SLAM3::System* m_SLAM;

        bool doRectify;
        cv::Mat M1l,M2l,M1r,M2r;

        cv_bridge::CvImageConstPtr cv_ptrLeft;
        cv_bridge::CvImageConstPtr cv_ptrRight;

        std::shared_ptr<message_filters::Subscriber<sensor_msgs::msg::Image> > left_sub;
        std::shared_ptr<message_filters::Subscriber<sensor_msgs::msg::Image> > right_sub;
        //std::shared_ptr<message_filters::Subscriber<sensor_msgs::msg::Imu> > imu_sub;

        

        

        std::shared_ptr<message_filters::Synchronizer<approximate_sync_policy> > syncApproximate;
    
    

        std::mutex mBufMutex;
};