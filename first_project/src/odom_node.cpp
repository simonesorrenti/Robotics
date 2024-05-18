#include <ros/ros.h>
#include <geometry_msgs/Quaternion.h>
#include <first_project/Odom.h>
#include <cmath>
#include <nav_msgs/Odometry.h>
#include <tf/transform_datatypes.h>
#include <first_project/ResetOdom.h>
#include <std_srvs/Empty.h>
#include <tf/transform_broadcaster.h>

class odom_node
{

	private:
	ros::NodeHandle nh; 
	ros::Subscriber sub;
	tf::TransformBroadcaster tf_broadcaster;

	public:
	  	odom_node(){
	  	sub = nh.subscribe("t265/odom", 1, &odom_node::odometry_to_tf, this);
		ROS_INFO("Odom reset to zero");
	}

	void odometry_to_tf(const nav_msgs::Odometry& odom) {
		ROS_INFO("Wow");
	}

};

int main(int argc, char** argv) {
	ros::init(argc, argv, "odom_node");

	odom_node my_odom_node;
	ros::spin();

	return 0;
}
