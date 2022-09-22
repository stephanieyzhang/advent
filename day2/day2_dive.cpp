#include <iostream>
#include <fstream>
#include <string>

int part1(std::ifstream &file) {
	int horizontal_position = 0;
	int depth = 0;

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
	file.close();
	int result = horizontal_position * depth;
	std::cout<<"Part 1: final horizontal position by final depth: " << result << "\n";
	return result;
}

int part2(std::ifstream &file) {
	int horizontal_position = 0;
	int depth = 0;
	int aim = 0;

	if(file.is_open()) {
		// Read each line of the input file.
		while(!file.eof()){ 
			std::string command;
			int unit;
			file >> command >> unit;
			
			if (command == "forward") {
				horizontal_position += unit;
				depth += unit * aim;
			} else if (command == "down") {
				aim += unit;
			} else if (command == "up") {
				aim -= unit;
			}
		}
	}
	file.close();
	int result = horizontal_position * depth;
	std::cout<<"Part 2: final horizontal position by final depth: " << result << "\n";
	return result;
}


int main() {
	// auto input_file = "D:\\advent\\day2\\day2_test_input.txt";
	auto input_file = "D:\\advent\\day2\\day2_input.txt";
  std::ifstream file(input_file);
	// part1(file);
	part2(file);
}