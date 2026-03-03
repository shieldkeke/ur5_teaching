# UR5 Teaching

This repository contains source code for a custom ROS 2 package (`ur5_teaching_cpp`).
It is not a prebuilt app, so you need to compile it with ROS 2 build tools (using `colcon`) to get an executable node.

If you are new to ROS 2, read this first:
[ROS 2 Colcon Tutorial (Humble)](https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Colcon-Tutorial.html)

## What this code does

- Implements a simple **joint goal** example.
- Communicates with **MoveIt** to move the arm to target joint positions.

## Build and run

```bash
# install build tools
sudo apt update
sudo apt install -y python3-colcon-common-extensions ros-${ROS_DISTRO}-moveit

# build (run in workspace root)
colcon build --symlink-install

# run
source /opt/ros/${ROS_DISTRO}/setup.bash
source install/setup.bash
ros2 run ur5_teaching_cpp test_move_arm_cpp --ros-args --params-file src/ur5_teaching_cpp/config/joint_goal.yaml
```

Joint targets are configured in [src/ur5_teaching_cpp/config/joint_goal.yaml](src/ur5_teaching_cpp/config/joint_goal.yaml).

## For more complex tasks

If you want advanced behavior (for example, making the end-effector draw a circle), you need to add extra code yourself, such as:

- Calling IK APIs.
- Generating Cartesian waypoints/trajectories in 3D space.
- Planning and executing those trajectories safely.

## Safety (real robot)

When using real hardware, always prioritize safety:

- Keep a clear workspace and emergency stop ready.
- Start with low speed/acceleration limits.
- Test in simulation first, then move to hardware.
