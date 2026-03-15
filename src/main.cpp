// main class of PoissonSolver
#include "grid.hpp"
#include "grid3d.hpp"
#include "diffusionsolver.hpp"
#include "diffusionsolver3d.hpp"
#include <iostream>

int main() {
	grid_ns::Grid grid(50,50, 10, 10); //first we create the grid object to map 2D to 1D
	//std::cout << "(" << point.i << ", " << point.j << ")\n";
	
	double dt{ 0.001};
	double alpha{ 0.1};
	diffusion_ns::DiffusionSolver dsolver(grid, dt, alpha);
	dsolver.solve(10000);

	//grid_ns::Grid3D grid(100, 100, 100, 10, 10, 10);
	
	//double dt{ 0.0001 };
	//double alpha{ 0.5 };
	//diffusion_ns::DiffusionSolver3D dsolver(grid, dt, alpha);
	//dsolver.solve3D(100);
	

	//psolver.solve(100); //advance the FTCS method 100 times
	//psolver.debug();
	return 0;


}
