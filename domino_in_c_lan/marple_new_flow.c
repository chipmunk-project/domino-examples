#include <iostream>


void marple_new_flow(int &new1, int &count) {
  if (count == 0) {
    count = 1;
    new1 = 1;
  }
}


int main(int argc, char **argv) {
  int new1, count;
  std::cout << "input the initial value of p.new: " << std::endl;
  std::cin >> new1;
  std::cout << "input the initial value of count: " << std::endl;
  std::cin >> count;

  // Run domino func
  marple_new_flow(new1, count);

  std::cout << "The updated values of p.new and count are " << new1 << ", " << count << std::endl;
  return 0;
}
