# MotionControl节点配置过程

### 1. 将configuration_files目录下的所使用的配置文件拷贝到控制器里

### 2. 结合实际项目更改配置文件中相应的配置，具体含义参见注释

### 3. 根据实际情况在CMakeList.txt中修改底盘电机类型，目前支持步科(kinco)和同毅(tongyi)
```
set(MOTOR_TYPE tongyi)
```

### 4. 根据实际情况在CMakeList.txt中修改处理器架构平台(arm或者x86)，以便链接相应平台下的动态库
```
set(ARCH x86)
```

### 5. 将motor_driver对应电机类型的中的动态库libmotor.so和rmos的动态库librmos.so拷贝到/usr/local/lib目录下，注意处理器架构，选择x86或者arm
```
sudo cp ./src/rmos/lib/x86/librmos.so /usr/local/lib
sudo cp ./src/motor_driver/${MOTOR_TYPE}/lib/x86/libmotor.so /usr/local/lib
or
sudo cp ./src/rmos/lib/arm/librmos.so /usr/local/lib
sudo cp ./src/motor_driver/${MOTOR_TYPE}/lib/arm/libmotor.so /usr/local/lib
```

### 6. 动态库生效 

```
sudo ldconfig /usr/sbin
```

### 7. catkin_make编译整个工程
```
cd catkin_ws
catkin_make
```
### 8. source ROS配置
```
source devel/setup.bash
```
### 9. 设置launch文件中的json配置文件路径
```
<launch>
    <node name="motion_control_node" pkg="motion_control" type="motion_control_node" args="
          -config 配置文件路径"
          output="screen">
    </node>
</launch>
```
### 10. 运行节点 roslaunch motion_control motion_control.launch
```
roslaunch motion_control motion_control.launch
```