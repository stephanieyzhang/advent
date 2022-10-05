#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Calculate the number of bits for the binary numbers in the report.
// This is assuming that each line of the report has the same number of bits.
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

std::string part2Helper(std::vector<std::string> report, int index, bool oxygen) {
  if (report.size() == 1) {
    return report[0];
  }

  int num_of_ones = 0;
  int num_of_zeros = 0;
  for (std::string line : report) {
    line[index] == '1' ? num_of_ones++ : num_of_zeros++;
  }
  char bit_criteria = oxygen ? (num_of_ones >= num_of_zeros? '1' : '0') :
                                (num_of_ones >= num_of_zeros ? '0' : '1');
  report.erase(std::remove_if(report.begin(), report.end(), 
                              [index, bit_criteria](const std::string &line) {
                                  return line[index] != bit_criteria; 
                              }), 
                              report.end());
  return part2Helper(report, index + 1, oxygen);
}

void part2(std::ifstream &file) {
  int num_of_bits = getNumberOfBits(file);

  // Create copies of the input to calculate the oxygen and co2 ratings.
  std::vector<std::string> oxygen_report;
  std::vector<std::string> co2_report;
  std::string line;
  
  while (file >> line) {
  oxygen_report.push_back(line);
  co2_report.push_back(line);
  }

  std::string oxygen_rating_string = part2Helper(oxygen_report, 0, true);
  std::string co2_rating_string = part2Helper(co2_report, 0, false);

  int oxygen_rating = 0;
  int co2_rating = 0;
  for (int i = 0; i < num_of_bits; i++) {
    oxygen_rating += (oxygen_rating_string[i] == '1') ? std::pow(2, (num_of_bits - 1 - i)) : 0;
    co2_rating += (co2_rating_string[i] == '1') ? std::pow(2, (num_of_bits - 1 - i)) : 0;
  }
  std::cout << "Part 2: What is the life support rating?: " << oxygen_rating * co2_rating << "\n";
}

int main() {
  // auto input_file = "D:\\advent\\day3\\day3_test_input.txt";
  auto input_file = "D:\\advent\\day3\\day3_input.txt";
  std::ifstream file(input_file);
  // part1(file);
  part2(file);
}