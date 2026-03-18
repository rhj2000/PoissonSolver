#include "consolemenu.hpp"
#include "grid.hpp"
#include "grid3d.hpp"
#include "diffusionsolver.hpp"
#include "diffusionsolver3d.hpp"
#include "run_solver.hpp"
#include <iostream>
#include <limits> // for std::numeric_limits

namespace ui_ns {

	void ConsoleMenu::catch_extraction_fail() {
		if (!std::cin) { //If previous extraction failed
			std::cin.clear(); //Revert to normal operation mode
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Remove bad input
		}
	}

	void ConsoleMenu::run() {

		bool running{ true };
		int choice{};
		bool menu_token{true };
		//std::cin >> choice;
	

		while (running){
			if (menu_token) {
				std::cout << "=== Diffusion Solver Menu === \n";
				std::cout << "=    1. Run 2D Simulation   = \n";
				std::cout << "=    2. Run 3D Simulation   = \n";
				std::cout << "=    3.      Exit           = \n";
				std::cout << "============================= \n";
				std::cin >> choice;
				catch_extraction_fail();
			}
			switch (choice) {
				case 1:	
				{
					run_simulation(50, 50, 10, 10, 0.001, 0.1, 1000);
					running = true;
					menu_token = true;
					break;
				}
				case 2:
				{
					std::cout << "do nothing.";
					running = false;
					menu_token = false;
					break;
				}
				case 3:
				{
					running = false;
					menu_token = false;
					break;
				}
				default:
				{
					std::cout << "Invalid choice. Please try again: ";
					std::cin >> choice;
					catch_extraction_fail();
					running = true;
					menu_token = false;
					break;
				}
			}
		}

	}

}