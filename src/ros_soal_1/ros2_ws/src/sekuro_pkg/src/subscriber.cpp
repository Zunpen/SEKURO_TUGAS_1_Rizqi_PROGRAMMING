#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class PilotSubscriber : public rclcpp::Node
{
public:
    PilotSubscriber() : Node("jack_cooper")
    {
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "titan_protocol",
            10,
            std::bind(&PilotSubscriber::callback, this, std::placeholders::_1));
    }

private:
    void callback(const std_msgs::msg::String::SharedPtr msg)
    {
        std::string command = msg->data;

        if(command == "Protocol 1")
        {
            RCLCPP_INFO(this->get_logger(), "Pilot J.Cooper: Link established, BT.");
        }
        else if(command == "Protocol 2")
        {
            RCLCPP_INFO(this->get_logger(), "Pilot Cooper: Copy that. Mission acknowledged.");
        }
        else if(command == "Protocol 3")
        {
            RCLCPP_INFO(this->get_logger(), "Pilot J.Cooper: I've got your back.");
        }
        else if(command == "END")
        {
            RCLCPP_INFO(this->get_logger(), "Pilot J.Cooper: See you on the other side, BT.");
            rclcpp::shutdown();
        }
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PilotSubscriber>());
    rclcpp::shutdown();
    return 0;
}