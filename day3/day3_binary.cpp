#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

struct Counter {
  int zeros;
  int ones;
};

// Calculate the number of bits for the binary numbers in the report.
// This is assuming that each line of the report has the same number of bits.
// (otherwise none of this works oops).
int getNumberOfBits(std::ifstream &file) {
  std::string line;
  int num_of_bits = 0;
  std::getline(file, line);
  file.seekg(0);
  return line.size();
}

void part1(std::ifstream &file) {
  int num_of_bits = getNumberOfBits(file);
  int gamma = 0;
  int epsilon = 0;

  for (int i = 0; i < num_of_bits; i++) {
    // Reset to the top of the file.
    file.clear();
    file.seekg(0);

    int num_of_ones = 0;
    int num_of_zeros = 0;
    std::string line;
    while (file >> line) {
      line[i] == '1' ? num_of_ones++ : num_of_zeros++;
    }
    (num_of_ones > num_of_zeros) ? gamma += std::pow(2, (num_of_bits - 1 - i)) : 
                                   epsilon += std::pow(2, (num_of_bits - 1 - i));
  }
  std::cout << "Part 1: What is the power consumption?: " << gamma * epsilon << "\n";
}

int main() {
  auto input_file = "D:\\advent\\day3\\day3_test_input.txt";
  // auto input_file = "D:\\advent\\day3\\day3_input.txt";
  std::ifstream file(input_file);
  part1(file);
  // part2(file);
}