source ./install/setup.bash
cmds=(
	"ros2 launch learn_ros_simulation rm_simulation.launch.py world:=CUBE use_sim_time:=True gui:=True"
)

for cmd in "${cmds[@]}"
do
	echo Current CMD : "$cmd"
	gnome-terminal -- bash -c "cd $(pwd);source install/setup.bash;$cmd;exec bash;"
	sleep 0.2
done
