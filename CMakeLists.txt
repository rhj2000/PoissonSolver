cmake_minimum_required(VERSION 3.10)
project(PoissonSolver)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include your own headers
include_directories(include)

# Create executable
add_executable(poisson_solver
    src/main.cpp
    src/grid.cpp
    src/poissonsolver.cpp
)


