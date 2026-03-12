/**
 * Author: Viswa
 * File: beamlet_star_ros_node.cpp
 */

#include "rclcpp/rclcpp.hpp"

class BeamletStarRosNode : public rclcpp::Node
{
private:

public:
    BeamletStarRosNode() : Node("beamlet_star_ros_node")
    {
        RCLCPP_INFO(get_logger(), "Beamlet star project initialized");
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<BeamletStarRosNode>());
    rclcpp::shutdown();
}
