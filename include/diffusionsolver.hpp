#pragma once
#include <vector>

namespace grid_ns {
	class Grid; //forward declaration of Grid tells the compiler that Grid exists 
}	

namespace io_ns {
	class ConsoleWriter; //need this for friend class declaration
}

namespace diffusion_ns {

	class DiffusionSolver {

	public:

		DiffusionSolver(const grid_ns::Grid& g, double dt, double alpha);
		double laplacian(int i, int j) const;
		double source(int i, int j) const;
		void solve(int steps);
		void debug();

		friend class io_ns::ConsoleWriter;

	private:
		const grid_ns::Grid& grid_;
		std::vector<double> u_; //current timestep
		std::vector<double> u_new_; //next timestep
		double dt_; //interval
		double alpha_; //Diffusivity parameter for FTCS
		int iteration_; //Diagnostic parameter for solver performance

		void setBoundaryConditions();
	};

}
