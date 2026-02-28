#pragma once
#include <vector>

namespace grid_ns {
	class Grid; //forward declaration of Grid tells the compiler that Grid exists 
}

namespace poisson_ns {

	class PoissonSolver {

	public:

		//PoissonSolver(const grid_ns::Grid &g) : grid_(g) {}
		//PoissonSolver(const grid_ns::Grid &g);
		PoissonSolver(const grid_ns::Grid& g, double dt, double alpha);
		void solve(int steps);
		void debug();

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
