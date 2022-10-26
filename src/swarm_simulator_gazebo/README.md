

```
source /usr/share/gazebo/setup.sh
```

```
ros2 launch swarm_simulator_gazebo empty_world.launch.py 
```

The launch file includes gazebo's launch file, and this means its launch arguments can be used.

verbose, gui, server.

world can be set to change which .world file is used.