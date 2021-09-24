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
    $ git clone https://github.com/omarosamahu/ORB_SLAM3-ros2.git
Change this path in cmake /home/conti/ORB_SLAM3/Examples/ROS/ORB_SLAM3 to your ORB_SLAM3 dir 
    $ cd ..
    $ colcon build






Add these two lines in your .bashrc in your home directory 
    source ws/install/setup.sh
    export LD_LIBRARY_PATH=PATH_TO_PANGOLIN/build/src/:PATH_TO_ORB_SLAM3/Thirdparty/DBoW2/lib:PATH_TO_ORB_SLAM3/Thirdparty/g2o/lib:PATH_TO_ORB_SLAM3/lib:$LD_LIBRARY_PATH


### Usage

Run the monocular SLAM node

    $ ros2 run orb_wrapper mono PATH_TO_VOCABULARY PATH_TO_YAML_CONFIG_FILE

You can find the vocabulary file in the ORB_SLAM3 repository (e.g. `ORB_SLAM3/Vocabulary/ORBvoc.txt`)

You can run the `stereo` node by using 

    $ ros2 run orb_wrapper stereo PATH_TO_VOCABULARY PATH_TO_YAML_CONFIG_FILE BOOL_RECTIFY
