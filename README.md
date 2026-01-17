```bash
# install build tools
sudo apt update
sudo apt install -y python3-colcon-common-extensions ros-${ROS_DISTRO}-moveit

# build
colcon build --symlink-install

# run
source /opt/ros/${ROS_DISTRO}/setup.bash
source install/setup.bash
ros2 run ur5_teaching_cpp test_move_arm_cpp --ros-args --params-file src/ur5_teaching_cpp/config/joint_goal.yaml
```

joints are configured in [src/ur5_teaching_cpp/config/joint_goal.yaml](src/ur5_teaching_cpp/config/joint_goal.yaml) 

Detailed Document:
https://www.kdocs.cn/l/cb2bHg1CPjMw