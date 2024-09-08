cmake_minimum_required(VERSION 3.8)
project(learn_subuscriber)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)

#设置可执行项，也就是我们之后执行ros2 run时执行的目标
add_executable(my_subscriber_exe src/subscriber.cpp)

#记得在此添加依赖
set(dependencies
rclcpp
sensor_msgs
std_msgs

)


#设置编译依赖，单单引用头文件是不够的，你还需要在编译时连接、包含这个头文件其所在的功能包
ament_target_dependencies(my_subscriber_exe ${dependencies})

#将编译好的可执行项安装
install(TARGETS my_subscriber_exe
  DESTINATION lib/${PROJECT_NAME}
)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
