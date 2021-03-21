# SWAP
## trace-cmd
* apt install trace-cmd
* trace-cmd record -p function_graph -M <cpu_mask>
* trace-cmd report trace.dat > trace.list
** report 結果の時刻の単位は秒。ping を 1 秒間隔で打って、trace-cmd record -p function -l icmp_rcv の結果を見ればわかる。

## cgroup
* sudo mkdir /sys/fs/cgroup/memory/test01
* echo $$ | sudo tee -a /sys/fs/cgroup/memory/test01/tasks
* echo 128M  | sudo tee -a /sys/fs/cgroup/memory/test01/memory.limit_in_bytes

## test-app
* make

* taskset -c 0 ./array_access
* vmstat 1 or vmstat -s (to show the number of swap-in/out)

* truncate --size 512M test_file
* taskset -c 0 ./mmap
* vmstat 1 (to show the number of I/O)
* cgroup により、page cache の量も制限できている模様


## readahead を除去
* 先読み処理が邪魔なので、VM_RAND_READ を設定する
* madvise(MADV_RANDOM)
