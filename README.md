# ros2-ORB_SLAM2
ROS2 node wrapping the ORB_SLAM2 library

If you want to integrate ORB_SLAM2 inside your ROS2 system, consider trying [this](https://github.com/alsora/ORB_SLAM2) fork of ORB_SLAM2 library which drops Pangolin dependency and streams all SLAM data through ROS2 topics.

### Requirements

 - [ROS2 Foxy](https://github.com/ros2/ros2/wiki/Installation)
 - [Pangolin](https://github.com/stevenlovegrove/Pangolin)
 - [OpenCV3](https://docs.opencv.org/3.0-beta/doc/tutorials/introduction/linux_install/linux_install.html)
 - [vision_opencv](https://github.com/ros-perception/vision_opencv/tree/ros2)
 - [message_filters](https://github.com/ros2/message_filters)

Note: The `vision_opencv` package requires OpenCV3. Make sure to build ORB_SLAM2 with the same OpenCV version otherwise strange run errors could appear.

The `message_filters` package is not required if you want to use only the Monocular SLAM node. 


### Build

Download Pangolin from this link (https://github.com/stevenlovegrove/Pangolin) then

    $ git checkout v0.6
    $ mkdir build && cd build
    $ cmake ..
    $ make -j4
    $ sudo make install

Download ORB_SLAM3 from this link https://github.com/UZ-SLAMLab/ORB_SLAM3.git then build it through this command

    $ ./build.sh

If you built ORB_SLAM3 following the instructions provided in its repository, you will have to tell CMake where to find it by exporting an environment variable that points to the cloned repository (as the library and include files will be in there).

    $ export ORB_SLAM3_ROOT_DIR=/path/to/ORB_SLAM3

Then you can build this package

    $ mkdir -p ws/src
    $ cd ws/src
    $ git clone https://github.com/alsora/ros2-ORB_SLAM3
    $ cd ..
    $ colcon build

### Usage

First source the workspace

    $ source ws/install/setup.sh

Then add to the LD_LIBRARY_PATH the location of ORB_SLAM2 library and its dependencies (the following paths may be different on your machine)

    $ export LD_LIBRARY_PATH=~/Pangolin/build/src/:~/ORB_SLAM3/Thirdparty/DBoW2/lib:~/ORB_SLAM3/Thirdparty/g2o/lib:~/ORB_SLAM3/lib:$LD_LIBRARY_PATH

Run the monocular SLAM node

    $ ros2 run ros2_orbslam mono PATH_TO_VOCABULARY PATH_TO_YAML_CONFIG_FILE

You can find the vocabulary file in the ORB_SLAM3 repository (e.g. `ORB_SLAM3/Vocabulary/ORBvoc.txt`)

You can run the `stereo` node by using 

    $ ros2 run ros2_orbslam stereo PATH_TO_VOCABULARY PATH_TO_YAML_CONFIG_FILE BOOL_RECTIFY
