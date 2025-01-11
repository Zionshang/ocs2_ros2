# OCS2_ROS2 Toolbox

Tested on Ubuntu 22.04 ROS2 Humble.

## 1 Dependency

* C++ compiler with C++17 support
* Eigen (v3.4)
* Boost C++ (v1.74)
* pinocchio (up-to-date)

## 2 Installation

The OCS2 library is written in C++17. It is tested under Ubuntu with library versions as provided in the package
sources.

### 2.1 Install Dependency

* Eigen

```bash
sudo apt update
sudo apt install libeigen3-dev 
```

* Pinocchio

[Recommended installation](https://stack-of-tasks.github.io/pinocchio/download.html)


### 2.3 Clone Repositories

* Create a new workspace or clone the project to your workspace

```bash
cd ~
mkdir -p ocs2_ros2_ws/src
```

* Clone the repository

```bash
cd ~/ocs2_ws/src
git clone https://github.com/Zionshang/ocs2_ros2.git
```

* build

```bash
cd ~/ocs2_ws
colcon build
```

## 3 Run Example

* Run the legged robot example
```bash
source ~/ocs2_ws/install/setup.bash
ros2 launch ocs2_legged_robot_ros legged_robot_ddp.launch.py
```

