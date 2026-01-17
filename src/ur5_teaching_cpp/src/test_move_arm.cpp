#include <memory>
#include <thread>
#include <vector>

#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  auto node = rclcpp::Node::make_shared("ur5_moveit_cpp");
  rclcpp::executors::SingleThreadedExecutor executor;
  executor.add_node(node);
  std::thread spinner([&executor]() { executor.spin(); });

  const auto planning_group = node->declare_parameter<std::string>("planning_group", "ur_manipulator");
  const auto joint_goal = node->declare_parameter<std::vector<double>>("joint_goal", std::vector<double>{0.0, -1.57, 0.0, -1.57, 0.0, 0.0});

  if (joint_goal.size() != 6) {
    RCLCPP_ERROR(node->get_logger(), "joint_goal must have 6 elements.");
    rclcpp::shutdown();
    spinner.join();
    return 1;
  }

  moveit::planning_interface::MoveGroupInterface move_group(node, planning_group);
  move_group.setJointValueTarget(joint_goal);

  moveit::planning_interface::MoveGroupInterface::Plan plan;
  bool success = (move_group.plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);
  if (success) {
    move_group.execute(plan);
  } else {
    RCLCPP_ERROR(node->get_logger(), "Planning failed.");
  }

  rclcpp::shutdown();
  spinner.join();
  return 0;
}
