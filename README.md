# SWAP
## trace-cmd
apt install trace-cmd
trace-cmd record -p function
trace-cmd report trace.dat > trace.list

## cgroup
sudo mkdir /sys/fs/cgroup/memory/test01
echo $$ | sudo tee -a /sys/fs/cgroup/memory/test01/tasks
echo 128M  | /sys/fs/cgroup/memory/test01/memory.limit_in_bytes

## test-app
make
./a.out
vmstat 1 (to show the number of swap-in/out)

