############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project binarycam
set_top top_function
add_files binarycam/cam.h
add_files binarycam/cam.cpp -cflags "-DTREE_SIZE=1024"
add_files -tb binarycam/test_bench.cpp -cflags "-DTREE_SIZE=1024 -Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb binarycam/hls_tree_bfs_1024.txt -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xc7z020-clg484-1} -tool vivado
create_clock -period 10 -name default
#source "./binarycam/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
