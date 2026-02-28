// main class of PoissonSolver
#include "grid.hpp"
#include "poissonsolver.hpp"
#include <iostream>

int main() {
	grid_ns::Grid grid(6, 6, 1, 1); //first we create the grid object to map 2D to 1D
	double dt{ 0.01 };
	double alpha{ 0.1 };
	poisson_ns::PoissonSolver psolver(grid, dt, alpha);
	psolver.solve(100);
	//psolver.debug();

	//psolver.solve(100); //advance the FTCS method 100 times

	return 0;


}
