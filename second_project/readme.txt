### MAPPING ###

tf_publisher.cpp: convert the odometry topic into tf
2D_laser_data.launch: create a map of the environment with 2D laser data
3D_laser_data.launch: create a map of the environment with 3D laser data
2D_laser_data_config.yaml: configurations to create the map with 2D laser data
3D_laser_data_config.yaml:configurations to create the map with 3D laser data
config_mapping.rviz: configurations for rviz tool

Node/Plugins used:
- slam_toolbox: mapping algorithm
- pointcloud_to_laserscan: provide a conversion mechanism from a point cloud representation to a simulated or virtual laser scan 2D representation
- rqt_tf_tree: provide a visualization of the tf (transform) tree in a robot system
- rviz: 3D visualization tool in ROS
- tf_publisher: convert the odometry topic into tf

Parameters used:
- Resolution: 0.08
- min_height: 0.2
- max_height: 0.8
- range_max: 30
- range_min: 0.5

### NAVIGATION ###

navigation.cpp: retrieve a set of waypoint from a csv file and publish the first goal (movebase handle the movement to it), when reached the next goal is published
navigation.launch: use the map to setup a stage navigation simulation
amcl.launch.xml: configurations for amcl
map_raw: contain all the maps created
config_nav.rviz: configurations for rviz tool
waypoints.csv: list of waypoints (x,y,heading)
second_3D.world: configurations for stage to set the size and pose of the map and the initial pose of the robot in the map
turtlebot.inc: configurations for stage to set the size of the robot and the fov and number of samples for the sensor

Configurations file for the navigation:
- costmap_common_params.yaml: assigns costs to each cell based on the presence of obstacles or other factors. The costmap allows the planner to generate collision-free paths and adjust the robot's behavior based on the environment's perceived costs.
- global_costmap_params.yaml: assigns costs to each cell based on the presence of obstacles or other factors. The costmap allows the planner to generate collision-free paths and adjust the robot's behavior based on the environment's perceived costs.
- local_costmap_params.yaml: assigns costs to each cell based on the presence of obstacles or other factors. The costmap allows the planner to generate collision-free paths and adjust the robot's behavior based on the environment's perceived costs.
- move_base_params.yaml
- teb_local_planner_params.yaml

Node/Plugins used:
- stage_ros: 2D robot simulator that provides a virtual environment for simulating and testing robotic systems
- move_base: provides a flexible and configurable framework for autonomous navigation of mobile robots. It integrates various components such as global and local planners, costmaps, and controllers to enable a robot to navigate safely in a given environment.
- map_server: load pre-generated maps, such as 2D occupancy grid maps or navigation maps
- rviz: 3D visualization tool in ROS
- navigation: retrieve a set of waypoint from a csv file and publish the first goal (movebase handle the movement to it), when reached the next goal is published
- amcl: package for probabilistic localization of mobile robots in an unknown environment. It utilizes the Monte Carlo Localization (MCL) algorithm, also known as particle filter localization, to estimate the robot's position and orientation relative to a map
- GlobalPlanner: the global planner is responsible for generating a high-level, long-term plan to navigate from the robot's current location to the desired goal position
- TebLocalPlannerROS: the local planner focuses on short-term, low-level control of the robot's movement. It takes into account the current sensor readings and local map information to generate trajectory commands that ensure obstacle avoidance and smooth robot motion

Parameters:
- map: second_3D.pgm
- initial position of the robot: 4.5 4.5 0.0
- fov: 180.0
- samples 360
- size of the robot: 0.60 0.40 0.40
- cost_scaling_factor: 30.0
- inflation_radius: 0.1
- width of the local map: 4
- height of the local map: 4










