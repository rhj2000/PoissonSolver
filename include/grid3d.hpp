#pragma once

namespace grid_ns {

	class Grid3D {

	private:
		int nx_, ny_, nz_;
		double dx_, dy_, dz_, lx_, ly_, lz_;

	public:
		Grid3D(int nx, int ny, int nz, double lx, double ly, double lz);

		int nx() const { return nx_; }
		int ny() const { return ny_; }
		int nz() const { return nz_; }
		double lx() const { return lx_; }
		double ly() const { return ly_; }
		double lz() const { return lz_; }
		double dx() const { return dx_; }
		double dy() const { return dy_; }
		double dz() const { return dz_; }

		int size() const;
		int index(int i, int j, int k) const;
		

		struct Index3D {
			int i;
			int j;
			int k;
		};
		Index3D cartesian_to_index3d(int x, int y, int z) const;

	};
}


