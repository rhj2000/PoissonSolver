#pragma once
#include <vector>

namespace grid_ns {
	class Grid3D; //forward declaration of Grid tells the compiler that Grid exists 
}

namespace diffusion_ns {

	class DiffusionSolver3D {

	public:
		DiffusionSolver3D(const grid_ns::Grid3D& g, double dt, double alpha);
		double laplacian3D(int i, int j, int k) const;
		double source3D(int i, int j, int k) const;
		void solve3D(int steps);
		void debug();

	private:
		const grid_ns::Grid3D& grid_;
		std::vector<double> u_; //current timestep
		std::vector<double> u_new_; //next timestep
		double dt_; //interval
		double alpha_; //Diffusivity parameter for FTCS
		int iteration_; //Diagnostic parameter for solver performance

		void setBoundaryConditions3D();
	};
}