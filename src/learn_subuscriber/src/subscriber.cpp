#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

//节点的类，节点的任何功能我们都将在此规定节点运行时的行为
class my_node : public rclcpp::Node
{
public:
    //节点的构造函数，我们将在此初始化节点的各个功能外设
    my_node() : Node("my_forst_node")
    {
        //配置定时器
        my_timer = this->create_wall_timer(
            std::chrono::milliseconds(100),/*配置该定时器每100ms执行一次*/
            std::bind(&my_node::timer_callback, this)/*配置该定时器的回调函数timer_callback*/
            );

    }
    

    
private:
    //一般来说，节点自带的函数与变量，指针的声明都不公开
    void timer_callback()
    {
    
    }
    // 声名定时器指针，可以定期执行函数
    rclcpp::TimerBase::SharedPtr my_timer;

};

//节点执行器
int main(int argc, char** argv) {
  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor node_executor;//创建节点执行器
  
  auto node = std::make_shared<my_node>();//创建节点指针

  node_executor.add_node(node->get_node_base_interface());//让节点执行器装载节点

  node_executor.spin();//让节点执行器开始执行

  rclcpp::shutdown();
  return 0;
}
