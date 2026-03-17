#include "run_solver.hpp"
#include "grid.hpp"
#include "diffusionsolver.hpp"


void run_simulation(int nx, int ny, double lx, double ly, double dt, double alpha, int time_steps) {
	grid_ns::Grid grid(nx, ny, lx, ly); //create grid object and pass reference to solver
	diffusion_ns::DiffusionSolver dsolver(grid, dt, alpha);
	dsolver.solve(time_steps);

}