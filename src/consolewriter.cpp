#include "consolewriter.hpp"
#include <iostream>
#include <string>
#include <algorithm>

namespace io_ns {

	void ConsoleWriter::print_ascii(const std::vector<double>& vect, int nx, int ny){ 
		//functionality:
		//write 2d solution to screen using symbols
		//write at each timestep or given timestep (could be start end or anywhere)

		//define ascii character space

		std::string levels{"A]B:C-D`E'F*G#H%I@J{K}L[,.N|O+P_Q)R(S^T&U>V<W/X;Y\"Z"};
		
		auto const minmax{ minmax_element(vect.begin(), vect.end()) };
		auto const min{ *minmax.first };
		auto max{ *minmax.second }; 

		if (-min > max) {
			max = -min;
		}

		size_t L = levels.size();

		//correct orientation for console write-out
		//write to screen like a cartesian grid
		for (int i = 0; i < ny; ++i) {
			for (int j = 0; j < nx; ++j) {
				int index = i * nx + j;

				double val = vect[index] / max; //domain [-1, 1]

				double normalized = (val + 1.0) / 2.0; //domain [0, 1]
				
				int level_index = static_cast<int>(normalized * (L - 1)); //index domain [0, length(levels) - 1]
				
				std::cout << levels[level_index] << "  ";

			}
			std::cout << '\n';
		}
		

	}

	void ConsoleWriter::print_ascii(const std::vector<double>& vect, int nx, int ny, int nz, int t, int k){
		//functionality:
		//write 3d solution to screen using symbols
		//write at each timestep or given timestep (could be start end or anywhere)

		std::cout << "do nothing.";

	}
}