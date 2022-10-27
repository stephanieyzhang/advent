#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

void part1(std::ifstream &file, int days) {
  std::vector<int> fishes;
  std::string fish;
  while(std::getline(file, fish, ',')) {
    fishes.push_back(std::stoi(fish));
  }

  for (int i = 0; i < days; i++) {
    std::vector<int> temp;
    int new_fishes = 0;
    std::transform(std::begin(fishes), std::end(fishes), std::begin(fishes), [&new_fishes](int x){
                  if ((x - 1) < 0) {
                    new_fishes++;
                    return 6;
                  } else {
                    return x - 1;
                  }});
    fishes.insert(fishes.end(), new_fishes, 8);
  }
  std::cout << "Part 1: Number of fish: " << fishes.size() << "\n";
}

void part2(std::ifstream &file, int days) {
  std::vector<uint64_t> fishes(9, 0);
  std::string fish;
  while(std::getline(file, fish, ',')) {
    fishes[std::stoi(fish)]++;
  }

  for (int i = 0; i < days; i++) {
    int day = i % 9;
    fishes[(day + 7) % 9] += fishes[day];
  }
  uint64_t total_fish = 0;
  for (auto& n : fishes)
     total_fish += n;
  std::cout << "Part 2: Number of fish: " << total_fish << "\n";
}

int main() {
  // auto input_file = "D:\\advent\\day6\\day6_test_input.txt";
  auto input_file = "D:\\advent\\day6\\day6_input.txt";
  std::ifstream file(input_file);
  // part1(file, 80);
  part2(file, 256);
}