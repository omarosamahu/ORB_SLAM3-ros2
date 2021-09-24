cmake_minimum_required(VERSION 3.5)
project(orb_wrapper)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
LIST(APPEND CMAKE_MODULE_PATH /home/conti/ORB_SLAM3/Examples/ROS/ORB_SLAM3/../../../cmake_modules)

find_package(OpenCV)
#if(NOT OpenCV_FOUND)
#   find_package(OpenCV 2.4.3 QUIET)
#   if(NOT OpenCV_FOUND)
#      message(FATAL_ERROR "OpenCV > 2.4.3 not found.")
#   endif()
#endif()

find_package(Eigen3 3.1.0 REQUIRED)
find_package(Pangolin REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(message_filters REQUIRED)
find_package(ament_cmake REQUIRED)



include_directories(
/home/conti/ORB_SLAM3/Examples/ROS/ORB_SLAM3
/home/conti/ORB_SLAM3/Examples/ROS/ORB_SLAM3/../../../
/home/conti/ORB_SLAM3/Examples/ROS/ORB_SLAM3/../../../include
/home/conti/ORB_SLAM3/Examples/ROS/ORB_SLAM3/../../../include/CameraModels
${Pangolin_INCLUDE_DIRS}
)

set(LIBS 
${OpenCV_LIBS} 
${EIGEN3_LIBS}
${Pangolin_LIBRARIES}
/home/conti/ORB_SLAM3/Examples/ROS/ORB_SLAM3/../../../Thirdparty/DBoW2/lib/libDBoW2.so
/home/conti/ORB_SLAM3/Examples/ROS/ORB_SLAM3/../../../Thirdparty/g2o/lib/libg2o.so
/home/conti/ORB_SLAM3/Examples/ROS/ORB_SLAM3/../../../lib/libORB_SLAM3.so
-lboost_system
)

message("Directory is: ${PROJECT_SOURCE_DIR}")

add_executable(stereo
#src/ros_stereo_inertial.cc
src/ros_stereo.cc
src/stereo-slam-node.cpp
)
ament_target_dependencies(stereo rclcpp sensor_msgs cv_bridge message_filters  Pangolin)
target_link_libraries(stereo
${LIBS}
)
install(TARGETS stereo
  DESTINATION lib/${PROJECT_NAME})

#if(BUILD_TESTING)
#  find_package(ament_lint_auto REQUIRED)
#  # the following line skips the linter which checks for copyrights
#  # uncomment the line when a copyright and license is not present in all source files
#  #set(ament_cmake_copyright_FOUND TRUE)
#  # the following line skips cpplint (only works in a git repo)
#  # uncomment the line when this package is not in a git repo
#  #set(ament_cmake_cpplint_FOUND TRUE)
#  ament_lint_auto_find_test_dependencies()
#endif()

ament_package()
