 #include <ros/ros.h>
 #include <move_base_msgs/MoveBaseAction.h>
 #include <actionlib/client/simple_action_client.h>
 #include <fstream>
 #include <iostream>
 #include <boost/filesystem.hpp>
 
 int main(int argc, char** argv){
   ros::init(argc, argv, "navigation");
   ros::NodeHandle nh;
 
   actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> ac("move_base", true);

   ROS_INFO("Waiting for the move_base action server to come up");
   ac.waitForServer(); //will wait for infinite time
   
   std::string waypointsFilePath;
   nh.getParam("/waypoints", waypointsFilePath);

   std::ifstream file(waypointsFilePath);     
    if (!file.is_open()) {
        std::cout << "Unable to open file csv with waypoints" << std::endl;
        return 1;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::string cell;
        std::stringstream lineStream(line);
        
        while (std::getline(lineStream, cell, ',')) {
            row.push_back(cell);
        }

	move_base_msgs::MoveBaseGoal goal;
	 
	goal.target_pose.header.frame_id = "map";
	goal.target_pose.header.stamp = ros::Time::now();
	goal.target_pose.pose.position.x = std::stod(row[0]);
	goal.target_pose.pose.position.y = std::stod(row[1]);
	goal.target_pose.pose.orientation.w = std::stod(row[2]);
	 
	ROS_INFO("Sending goal");
	ac.sendGoal(goal);
	 
	ac.waitForResult();
	 
	if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
		ROS_INFO("The robot has reached the waypoint");
	else
		ROS_INFO("The robot failed to reach the waypoint");

        std::cout << std::endl;
    }
    
    file.close();
    
    ros::spin();

    return 0;

}
