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

		std::string levels{" .:-`'*#%@"};
		
		auto const minmax{ minmax_element(vect.begin(), vect.end()) };
		auto const min{ *minmax.first };
		auto max{ *minmax.second }; 

		if (-min > max) {
			max = -min;
		}

		//correct orientation for console write-out
		//write to screen like a cartesian grid
		for (int i = 0; i < ny; ++i) {
			for (int j = 0; j < nx; ++j) {
				int index = i * nx + j;

				double val = vect[index] / max;

				if (val < -0.8)
					std::cout << levels[0];
				else if (val >= -0.8 && val < -0.6)
					std::cout << levels[1];
				else if (val >= -0.6 && val < -0.4)
					std::cout << levels[2];
				else if (val >= -0.4 && val < -0.2)
					std::cout << levels[3];
				else if (val >= -0.2 && val < 0)
					std::cout << levels[4];
				else if (val >= 0.0 && val < 0.2)
					std::cout << levels[5];
				else if (val >= 0.2 && val < 0.4)
					std::cout << levels[6];
				else if (val >= 0.4 && val < 0.6)
					std::cout << levels[7];
				else if (val >= 0.6 && val < 0.8)
					std::cout << levels[8];
				else if (val >= 0.8 && val <= 1.0)
					std::cout << levels[9];
				
				std::cout << "  ";

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