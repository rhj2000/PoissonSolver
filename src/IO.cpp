#include "io.hpp"
#include <vector>
#include <string_view>
#include <fstream>

namespace io_ns {

	CSVWriter::CSVWriter(std::string_view filename) : file_(filename) {}

	void CSVWriter::vector_to_csv(const std::vector<double>& vect, int dim_x, int dim_y) { //need to make the vector a template
		std::ofstream outf{file_, std::ios::out};
		for (int i = dim_y - 1; i >= 0; --i) { 
			//write from the last row (bottom of matrix) first since we want a homemorphic x,y,(z) representation
			//first row printed is the top row of the 'image'
			for (int j = 0; j < dim_x; ++j) {
				int index = i * dim_x + j;
				outf << vect[index] << ',';
			}
			outf << '\n';
		}
	}

	CSVWriter3D::CSVWriter3D(std::string_view filename) : file_(filename) {}

	void CSVWriter3D::vector_to_csv3d(const std::vector<double>& vect, int dim_x, int dim_y, int dim_z) {
		std::ofstream outf{ file_, std::ios::out };
		for (int k{ 0 }; k < dim_z; ++k) {
			for (int i = dim_y - 1; i >= 0; --i) {
				for (int j = 0; j < dim_x; ++j) {
					int index = j + i * dim_x + k * dim_x * dim_y;
					outf << vect[index] << ',';
				}
				outf << '\n';
			}
			outf << '\n';
			outf << '\n';

		}
	}

	VTKWriter::VTKWriter(std::string_view filename) : file_(filename) {}

	void VTKWriter::write_vtk(
		const std::vector<double>& vect,
		int nx, int ny, int nz,
		double dx, double dy, double dz)
	{
		std::ofstream outf{ file_ };

		outf << "# vtk DataFile Version 3.0\n";
		outf << "Diffusion field\n";
		outf << "ASCII\n";
		outf << "DATASET STRUCTURED_POINTS\n";

		outf << "DIMENSIONS " << nx << " " << ny << " " << nz << "\n";
		outf << "ORIGIN 0 0 0\n";
		outf << "SPACING " << dx << " " << dy << " " << dz << "\n";

		outf << "POINT_DATA " << nx * ny * nz << "\n";
		outf << "SCALARS u double\n";
		outf << "LOOKUP_TABLE default\n";

		for (size_t i = 0; i < vect.size(); ++i)
			outf << vect[i] << "\n";
	}


}