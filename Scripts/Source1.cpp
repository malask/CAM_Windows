#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <direct.h>
#include <fstream>

int main() {

	std::vector <std::string> cam, results, flags, proyects;
	std::vector <int> tamanos;
	std::string comillas("\"\"");
	
	proyects.push_back("cam_basica");
	proyects.push_back("cam_basica_optimizada");
	proyects.push_back("cam_basica_opt_parada");
	proyects.push_back("cam_binaria");
	proyects.push_back("cam_binaria_optimizada");
	proyects.push_back("cam_binaria_opt_parada");
	proyects.push_back("cam_binaria_reader");
	proyects.push_back("cam_binaria_submemorias");
	proyects.push_back("cam_hash");
	proyects.push_back("cam_hash_ideal");

	for (int i = 0; i < proyects.size(); i++) _mkdir(proyects[i].c_str());
	
	for (int j = 0; j < proyects.size(); j++) {
		std::string path(".\\" + proyects[j]+"\\");
		std::ofstream fichero(path+"script.tcl");
		fichero << "set tamanos [list 128 256 512 1024 2048 4096 8192]" << std::endl;
		fichero << "set name \"" << proyects[j] << "\"" << std::endl;
		fichero << "set cam \"cam.cpp\"" << std::endl;
		fichero << "set cust_cam \"cam.h\"" << std::endl;
		fichero << "set rawDatFile \"./Data/data_\"" << std::endl;
		fichero << "set rawResFile \"./Results/results_\"" << std::endl;
		fichero << "set flag {\"-DTREE_SIZE=}" << std::endl;

		fichero << "foreach i $tamanos {" << std::endl;
		fichero << "	append fullDatFile $rawDatFile $i .cpp" << std::endl;
		fichero << "	append fullResFile $rawResFile $i .cpp" << std::endl;
		fichero << "	append proyect_name $name \"_\" $i" << std::endl;
		fichero << "	append short_flag $flag $i {\"}" << std::endl;
		fichero << "	append long_flag $flag $i \" -Wno-unknown-pragmas\" {\"}" << std::endl;
		fichero << "	open_project -reset $proyect_name" << std::endl;
		fichero << "	add_files ./HLS_cams/" << proyects[j] << "/cam.cpp -cflags $short_flag" << std::endl;
		fichero << "	add_files ./HLS_cams/" << proyects[j] << "/cam.h -cflags $short_flag" << std::endl;
		fichero << "	add_files $fullDatFile" << std::endl;
		fichero << "	add_files $fullResFile" << std::endl;
		fichero << "	add_files -tb ./HLS_cams/" << proyects[j] << "/test_bench.cpp -cflags $long_flag -csimflags \"-Wno-unknown-pragmas\"" << std::endl;
		fichero << "	set_top top_function" << std::endl;
		fichero << "	open_solution -reset solution1" << std::endl;
		fichero << "	set_part {xc7z020-clg484-1} -tool vivado" << std::endl;
		fichero << "	create_clock -period 10 -name default" << std::endl;
		fichero << "	csim_design" << std::endl;
		fichero << "	csynth_design" << std::endl;
		fichero << "	cosim_design" << std::endl;
		fichero << "	export_design -flow impl -rtl verilog -format ip_catalog" << std::endl;
		fichero << "	set fullDatFile \"\"" << std::endl;
		fichero << "	set fullResFile \"\"" << std::endl;
		fichero << "	set proyect_name \"\"" << std::endl;
		fichero << "	set short_flag \"\"" << std::endl;
		fichero << "	set long_flag \"\"" << std::endl;
		fichero << "}" << std::endl;
		fichero << "exit" << std::endl;
		fichero.close();
			
	} 
	return 0;
}
/*open_project cam_simple
set_top top_function
add_files cam_simple/cam.cpp -cflags "-DTREE_SIZE=8192"
add_files cam_simple/cam.h -cflags "-DTREE_SIZE=8192"
add_files cam_simple/data_8192.cpp
add_files cam_simple/results_8192.cpp
add_files -tb cam_simple/test_bench.cpp -cflags "-DTREE_SIZE=8192 -Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "binaria_normal_optimizada"
set_part {xc7z020-clg484-1} -tool vivado
create_clock -period 10 -name default
#source "./cam_simple/binaria_normal_optimizada/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog*/