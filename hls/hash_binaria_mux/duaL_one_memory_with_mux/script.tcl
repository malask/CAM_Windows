############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project cam_hash
set_top top_function
add_files cam_hash/cam.cpp -cflags "-DTREE_SIZE=1024"
add_files cam_hash/cam.h -cflags "-DTREE_SIZE=1024"
add_files -tb cam_hash/hls_tree_bfs_1024.txt
add_files -tb cam_hash/test_bench.cpp -cflags "-DTREE_SIZE=1024"
open_solution "duaL_one_memory_with_mux"
set_part {xc7z020-clg484-1}
create_clock -period 10 -name default
#source "./cam_hash/duaL_one_memory_with_mux/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
