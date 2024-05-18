#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>

class tf_publisher
{

	private:
	ros::NodeHandle nh; 
	ros::Subscriber sub;
	tf::TransformBroadcaster tf_broadcaster;

	public:
	  	tf_publisher(){
	  	sub = nh.subscribe("t265/odom", 1, &tf_publisher::odometry_to_tf, this);
		ROS_INFO("tf_publisher node started!");
	}

	void odometry_to_tf(const nav_msgs::Odometry& odom) {
		tf::Transform transform;
		transform.setOrigin(tf::Vector3(odom.pose.pose.position.x, odom.pose.pose.position.y, odom.pose.pose.position.z));
		transform.setRotation(tf::Quaternion(odom.pose.pose.orientation.x, odom.pose.pose.orientation.y, odom.pose.pose.orientation.z, odom.pose.pose.orientation.w));
		tf_broadcaster.sendTransform(tf::StampedTransform(transform, odom.header.stamp, "odom", "t265"));
		ROS_INFO("odometry_to_tf method called!");
	}

};

int main(int argc, char** argv) {
	ros::init(argc, argv, "tf_publisher");

	tf_publisher my_tf_publisher;
	ros::spin();

	return 0;
}
