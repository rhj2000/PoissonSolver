#include "grid3d.hpp"
#include <iostream>

namespace grid_ns {

	Grid3D::Grid3D(int nx, int ny, int nz, double lx, double ly, double lz) : nx_(nx), ny_(ny), nz_(nz), lx_(lx), ly_(ly), lz_(lz)
	{
		if (nx_ < 1 || ny_ < 1 || nz_ < 1 || lx_ <= 0 || ly_ <= 0 || lz_ <= 0) {
			throw std::invalid_argument("Grid3D parameters invalid");
		}

		dx_ = lx / (nx - 1);
		dy_ = ly / (ny - 1);
		dz_ = lz / (nz - 1);
	}

	int Grid3D::size() const
	{
		return nx_ * ny_ * nz_;
	}


	int Grid3D::index(int i, int j, int k) const
	{
		return j + i * nx_ + k * nx_ * ny_;
	}

	Grid3D::Index3D Grid3D::cartesian_to_index3d(int x, int y, int z) const {
		return { nx_ - y, x, z };
	}
}

