cmake_minimum_required(VERSION 3.10)
project(DiffusionSolver)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include your own headers
include_directories(include)

# Create executable
add_executable(diffusion_solver
	src/main.cpp	
	src/io.cpp
	src/grid3d.cpp 
	src/grid.cpp 
	src/diffusionsolver3d.cpp 
	src/diffusionsolver.cpp 
	src/consolewriter.cpp
)


