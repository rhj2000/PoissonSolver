#include "PoissonSolver.hpp"
#include "Grid.hpp"
#include <iostream>

namespace poisson_ns {

//This class knows about the Grid class. It will use Grid to implement a stencil.

PoissonSolver::PoissonSolver(const grid_ns::Grid &g, double dt) : grid_(g), dt_(dt) {}

void PoissonSolver::solver(int steps){
	//implement the stencil here (maybe later it can be put into another source file and namespace (stencil.ns?))
	//implement FTCS as the solver method
	
}

char PoissonSolver::debug(){
	//create local variables storing grid data
	//std::cout << sizeof(grid_);
	//std::cout << "Hello!";
	char str {'H'};
	return str;
}

}
