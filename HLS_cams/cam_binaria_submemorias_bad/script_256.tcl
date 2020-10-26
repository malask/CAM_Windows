open_project -reset cam_binaria_submemorias_256
add_files ./HLS_cams/cam_binaria_submemorias/cam.cpp -cflags "-DTREE_SIZE=256"
add_files ./HLS_cams/cam_binaria_submemorias/cam.h -cflags "-DTREE_SIZE=256"
add_files ./Data/data_256.cpp
add_files ./Results/results_256.cpp
add_files -tb ./HLS_cams/cam_binaria_submemorias/test_bench.cpp -cflags "-DTREE_SIZE=256 -Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
set_top top_function
open_solution -reset solution1
set_part {xc7z020-clg484-1} -tool vivado
create_clock -period 10 -name default
csim_design
csynth_design
cosim_design
export_design -flow impl -rtl verilog -format ip_catalog
exit