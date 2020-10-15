set tamanos [list 128 256 512 1024 2048 4096 8192]
set name "cam_binaria_opt_parada"
set cam "cam.cpp"
set cust_cam "cam.h"
set rawDatFile "./Data/data_"
set rawResFile "./Results/results_"
set flag {"-DTREE_SIZE=}
foreach i $tamanos {
	append fullDatFile $rawDatFile $i .cpp
	append fullResFile $rawResFile $i .cpp
	append proyect_name $name "_" $i
	append short_flag $flag $i {"}
	append long_flag $flag $i " -Wno-unknown-pragmas" {"}
	open_project -reset $proyect_name
	add_files ./HLS_cams/cam_binaria_opt_parada/cam.cpp -cflags $short_flag
	add_files ./HLS_cams/cam_binaria_opt_parada/cam.h -cflags $short_flag
	add_files $fullDatFile
	add_files $fullResFile
	add_files -tb ./HLS_cams/cam_binaria_opt_parada/test_bench.cpp -cflags $long_flag -csimflags "-Wno-unknown-pragmas"
	set_top top_function
	open_solution -reset solution1
	set_part {xc7z020-clg484-1} -tool vivado
	create_clock -period 10 -name default
	csim_design
	csynth_design
	cosim_design
	export_design -flow impl -rtl verilog -format ip_catalog
	set fullDatFile ""
	set fullResFile ""
	set proyect_name ""
	set short_flag ""
	set long_flag ""
}
exit
