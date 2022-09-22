#include <iostream>
#include <fstream>
#include <string>

int part1(std::ifstream &file) {
	int horizontal_position;
	int depth;

	if(file.is_open()) {
		// Read each line of the input file.
		while(!file.eof()){ 
			std::string command;
			int unit;
			file >> command >> unit;
			
			if (command == "forward") {
				horizontal_position += unit;
			} else if (command == "down") {
				depth += unit;
			} else if (command == "up") {
				depth -= unit;
			}
		}
	}
	int result = horizontal_position * depth;
	std::cout<<"Part 1: final horizontal position by final depth: " << result << "\n";
	return result;
}


int main() {
	auto input_file = "day2_test_input.txt";
  std::ifstream file(input_file);
	part1(file);
}