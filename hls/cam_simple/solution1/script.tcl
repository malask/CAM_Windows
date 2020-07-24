############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project cam_simple
set_top top_function
add_files cam_simple/cam.cpp -cflags "-DTREE_SIZE=1024"
add_files cam_simple/cam.h -cflags "-DTREE_SIZE=1024"
add_files -tb cam_simple/hls_tree_bfs_1024.txt -cflags "-DTREE_SIZE=1024"
add_files -tb cam_simple/test_bench.cpp -cflags "-DTREE_SIZE=1024"
open_solution "solution1"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
config_sdx -optimization_level none -target none
config_export -vivado_optimization_level 2
#source "./cam_simple/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
