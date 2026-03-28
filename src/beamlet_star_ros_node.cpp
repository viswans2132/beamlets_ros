/**
 * Author: Viswa
 * File: beamlet_star_ros_node.cpp
 * Description: ROS2 main node for the beamlet star project
 */

#include "rclcpp/rclcpp.hpp"

#include <vector>
#include <sstream>
#include <stdexcept>

class BeamletStarRosNode : public rclcpp::Node
{

private:
    int rows_;
    int cols_;
    int smax_;
    double alpha_;
    std::vector<int64_t> grid_flat_;

    std::vector<std::vector<int>> grid_;

    void declareParameters()
    {
        declare_parameter("rows", 0);
        declare_parameter("cols", 0);
        declare_parameter("grid", std::vector<int64_t>());
        declare_parameter("smax", 0);
        declare_parameter("alpha", 0.0);
    }

    void loadParameters()
    {
        rows_ = get_parameter("rows").as_int();
        cols_ = get_parameter("cols").as_int();
        grid_flat_ = get_parameter("grid").as_integer_array();
        smax_ = get_parameter("smax").as_int();
        alpha_ = get_parameter("alpha").as_double();

        validateParameters();
        buildGrid();
    }

    void validateParameters()
    {
        if (rows_ <= 0 || cols_ <= 0)
        {
            throw std::runtime_error("Rows and Cols must be > 0");
        }

        if (grid_flat_.size() != static_cast<size_t>(rows_ * cols_))
        {
            throw std::runtime_error("Grid size does not match rows * cols");
        }
    }

    void buildGrid()
    {
        grid_.resize(rows_, std::vector<int>(cols_));

        int k = 0;
        for (int i = 0; i < rows_; ++i)
        {
            for (int j = 0; j < cols_; ++j)
            {
                grid_[i][j] = static_cast<int>(grid_flat_[k++]);
            }
        }
    }

    void printGrid()
    {
        RCLCPP_INFO(get_logger(), "Beamlet star config loaded!");
        RCLCPP_INFO(get_logger(),
                    "Rows=%d Cols=%d smax=%d alpha=%f",
                    rows_, cols_, smax_, alpha_);

        RCLCPP_INFO(get_logger(), "Grid:");

        for (const auto &row : grid_)
        {
            std::stringstream ss;
            for (auto val : row)
            {
                ss << val << " ";
            }
            RCLCPP_INFO(get_logger(), "%s", ss.str().c_str());
        }
    }

    public:
    BeamletStarRosNode() : Node("beamlet_star_ros_node")
    {
        RCLCPP_INFO(get_logger(), "Initializing Beamlet Star Node...");

        try {
            declareParameters();
            loadParameters();
            printGrid();

            RCLCPP_INFO(get_logger(), "Beamlet Star Node initialized successfully!");
        } catch (const std::exception &e){
            RCLCPP_ERROR(get_logger(), "Initialization failed: %s", e.what());
            rclcpp::shutdown();
            throw;
        }
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<BeamletStarRosNode>());
    rclcpp::shutdown();
    return 0;
}