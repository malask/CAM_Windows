#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <direct.h>
#include <fstream>

int main() {
	_mkdir("C:\\Users\\manug\\source\\repos\\Project1\\Project1v2\\Script");
	std::vector <std::string> cam, results, flags;
	std::vector <int> tamanos;
	std::string comillas("\"\"");

	for (int i = 7; i < 14; i++) {
		int size = pow(2, i);
		tamanos.push_back(size);
		std::ofstream fichero("prueba_" + std::to_string(size) + ".txt");

		cam.push_back("data_" + std::to_string(size) + ".cpp");
		results.push_back("results_" + std::to_string(size) + ".cpp");
		flags.push_back("\"-DTREE_SIZE=" + std::to_string(size) );
		fichero.close();
	}
	for (int i = 0; i < 7; i++) {
		std::ofstream fichero("script_" + std::to_string(tamanos[i]) + ".tcl");
		fichero << "open_project -reset cam" << std::endl;
		fichero << "add_files cam.cpp -cflags " << flags[i] << "\"" <<  std::endl;
		fichero << "add_files cam.h -cflags " << flags[i] << "\"" << std::endl;
		fichero << "add_files " << cam[i] << std::endl;
		fichero << "add_files " << results[i] << std::endl;
		fichero << "add_files -tb test_bench.cpp -cflags " << flags[i] << " -Wno-unknown-pragmas\" -csimflags \"-Wno-unknown-pragmas\"" << std::endl;
		fichero << "set_top top_function" << std::endl;
		fichero << "open_solution -reset solution1" << std::endl;
		fichero << "set_part {xc7z020-clg484-1} -tool vivado" << std::endl;
		fichero << "create_clock -period 10 -name default" << std::endl; 
		fichero << "csim_design" << std::endl;
		fichero << "csynth_design" << std::endl;
		fichero << "cosim_design" << std::endl;
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