# OCS2_ROS2 Toolbox

## 1 Installation

### 2.1 Prerequisites

The OCS2 library is written in C++17. It is tested under Ubuntu with library versions as provided in the package
sources.

Tested system and ROS2 version:

* Ubuntu 24.04 ROS2 Jazzy
* Ubuntu 22.04 ROS2 Humble

### 2.2 Dependencies

* C++ compiler with C++17 support
* Eigen (v3.4)
* Boost C++ (v1.74)

### 2.3 Clone Repositories

* Create a new workspace or clone the project to your workspace

```bash
cd ~
mkdir -p ocs2_ws/src
```

* Clone the repository

```bash
cd ~/ocs2_ws/src
git clone https://github.com/legubiao/ocs2_ros2
git submodule update --init --recursive
```

* rosdep

```bash
cd ~/ocs2_ws
rosdep install --from-paths src --ignore-src -r -y
```

### 2.4 [Basic Examples](basic%20examples/)

Quick start guide:

* Compile legged robot example
    ```bash
    cd ~/ocs2_ws
    colcon build --packages-up-to ocs2_legged_robot_ros
    ```
* Run the legged robot example
    ```bash
    source ~/ocs2_ws/install/setup.bash
    ros2 launch ocs2_legged_robot_ros legged_robot_ddp.launch.py
    ```

![legged_robot](.images/legged_demo.png)

[![](http://i0.hdslb.com/bfs/archive/1bf12ba98ed8e7fe01594bb2a713ddafdd580488.jpg)](https://www.bilibili.com/video/BV12vv9eGEns/)

## 3. Advanced Examples

[![](http://i1.hdslb.com/bfs/archive/a53bab50141165eb452aa0763a9a5b9a51a7ca67.jpg)](https://www.bilibili.com/video/BV1gSHLe3EEv/)

### 3.1 [Perceptive Locomotion](advance%20examples/ocs2_raisim/)

![perceptive_side](.images/perception_side.png)

![perceptive_hurdles](.images/perception_hurdles.png)

### 3.2 [RaiSim Simulation](advance%20examples/ocs2_raisim/)

![raisim](.images/raisim.png)

![raisim_rviz](.images/raisim_rviz.png)

### 3.3 [MPC-Net](advance%20examples/ocs2_mpcnet/)

# 功能包解读

所有包：22个
ocs2_robotic_assets
ocs2_thirdparty
blasfeo_colcon
ocs2_msgs
ocs2_core
ocs2_oc
ocs2_mpc
ocs2_qp_solver
ocs2_robotic_tools
ocs2_ros_interfaces
ocs2_slp
hpipm_colcon
ocs2_ddp
ocs2_pinocchio_interface
ocs2_sqp
ocs2_ipm
ocs2_self_collision
ocs2_sphere_approximation
ocs2_centroidal_model
ocs2_self_collision_visualization
ocs2_legged_robot
ocs2_legged_robot_ros

ocs2_legged_robot_ros用到的包 18个
ocs2_thirdparty [0.08s]
ocs2_robotic_assets [0.08s]
blasfeo_colcon [0.09s]
ocs2_msgs [0.21s]
ocs2_core [0.18s]
ocs2_oc [0.15s]
ocs2_mpc [0.07s]
ocs2_qp_solver [0.09s]
ocs2_robotic_tools [0.10s]
ocs2_ros_interfaces [0.10s]
hpipm_colcon [0.10s]
ocs2_pinocchio_interface [0.11s]
ocs2_ddp [0.12s]
ocs2_sqp [0.08s]
ocs2_ipm [0.09s]
ocs2_centroidal_model [0.16s]
ocs2_legged_robot [0.28s]
ocs2_legged_robot_ros [0.21s]
缺少了 ocs2_self_collision_visualization ocs2_slp ocs2_self_collision ocs2_sphere_approximation

