#include <iostream>
#define VALID_IP 102

void stateful_fw(int &array_index, int &src, int &dst, int &drop, int &established) {
  array_index = src + dst; // row indexed 2D array
  if (src == VALID_IP) {
    established = 1;
  } else {
    if (dst == VALID_IP) {
      drop = (established == 0);
    }
  }
}

int main(int argc, char **argv) {
  int array_index, src, dst, drop, established;
  std::cout << "input the initial value of p.array_index: " << std::endl;
  std::cin >> array_index;
  std::cout << "input the initial value of p.src: " << std::endl;
  std::cin >> src;
  std::cout << "input the initial value of p.dst: " << std::endl;
  std::cin >> dst;
  std::cout << "input the initial value of p.drop: " << std::endl;
  std::cin >> drop;
  std::cout << "input the initial value of established: " << std::endl;
  std::cin >> established;

  // Run domino func
  stateful_fw(array_index, src, dst, drop, established);

  std::cout << "The updated values of p.array_index, p.src, p.dst, p.drop and established are " << array_index << ", " << src << ", " << dst << ", " << drop << ", " << established << std::endl;
  return 0;
}
