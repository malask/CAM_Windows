open_project -reset cam
add_files cam.cpp -cflags "-DTREE_SIZE=256"
add_files cam.h -cflags "-DTREE_SIZE=256"
add_files data_256.cpp
add_files results_256.cpp
add_files -tb test_bench.cpp -cflags "-DTREE_SIZE=256 -Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
set_top top_function
open_solution -reset solution1
set_part {xc7z020-clg484-1} -tool vivado
create_clock -period 10 -name default
csim_design
csynth_design
cosim_design
