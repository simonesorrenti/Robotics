cmake_minimum_required(VERSION 2.8.3)
project(second_project)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS move_base roscpp std_msgs message_generation tf)

 
generate_messages(
   DEPENDENCIES
  std_msgs
 )


## Declare a catkin package
catkin_package( CATKIN_DEPENDS message_runtime)




## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})


add_executable(tf_publisher src/tf_publisher.cpp)
add_executable(navigation src/navigation.cpp)
add_dependencies(tf_publisher second_project_messages_generate_messages_cpp)
add_dependencies(navigation second_project_messages_generate_messages_cpp)
target_link_libraries(tf_publisher ${catkin_LIBRARIES})
target_link_libraries(navigation ${catkin_LIBRARIES})

