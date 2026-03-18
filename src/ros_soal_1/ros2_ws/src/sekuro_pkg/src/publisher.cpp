#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class BTPublisher : public rclcpp::Node
{
public:
    BTPublisher() : Node("bt_7274"), step(0)
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("titan_protocol", 10);

        timer_ = this->create_wall_timer(
            2s,
            std::bind(&BTPublisher::publish_message, this));
    }

private:
    void publish_message()
    {
        auto msg = std_msgs::msg::String();

        if(step == 0)
        {
            msg.data = "Protocol 1";
            RCLCPP_INFO(this->get_logger(), "BT-7274: Protocol 1 - Link to Pilot.");
        }
        else if(step == 1)
        {
            msg.data = "Protocol 2";
            RCLCPP_INFO(this->get_logger(), "BT-7274: Protocol 2 - Uphold the mission.");
        }
        else if(step == 2)
        {
            msg.data = "Protocol 3";
            RCLCPP_INFO(this->get_logger(), "BT-7274: Protocol 3 - Protect the Pilot.");
        }
        else
        {
            msg.data = "END";
            RCLCPP_INFO(this->get_logger(), "BT-7274: Mission complete.");
            publisher_->publish(msg);
            rclcpp::shutdown();
            return;
        }

        publisher_->publish(msg);
        step++;
    }

    int step;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<BTPublisher>());
    rclcpp::shutdown();
    return 0;
}