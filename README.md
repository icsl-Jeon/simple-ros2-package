# Simple ros2 package containing core and wrapper

## Installation

```
cd ~/ros2_ws/src
git clone https://github.com/icsl-Jeon/simple-ros2-package.git
cd ~/ros2_ws
colcon build --merge-install
```

## Running node

```
source ~/ros2_ws/install/local_setup.bash
ros2 run my_package_ros2 MyRosNode
```

### c_cpp_properties.json

As we installed with `--merge-install`, all you need for
`~/ros2_ws/.vscode/c_cpp_properties.json` is

```json
{
  "configurations": [
    {
      "browse": {
        "databaseFilename": "${default}",
        "limitSymbolsToIncludedHeaders": false
      },
      "includePath": [
        "/opt/ros/foxy/include/**",
        "/usr/include/**",
        "${workspaceFolder}/install/include/**"
      ],
      "name": "ROS",
      "intelliSenseMode": "gcc-x64",
      "compilerPath": "/usr/bin/gcc",
      "cStandard": "gnu11",
      "cppStandard": "c++17"
    }
  ],
  "version": 4
}
```
