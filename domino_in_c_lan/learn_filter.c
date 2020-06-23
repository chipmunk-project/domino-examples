#include <iostream>

void learn_filter(int &filter1_idx, int &filter2_idx, int &filter3_idx, int &member, int &filter1, int &filter2, int &filter3) {
  filter1_idx = filter1_idx;
  filter2_idx = filter2_idx;
  filter3_idx = filter3_idx;
  if (filter1 != 0 && filter2 != 0 && filter3 != 0) {
     member = 1;
  } else {
     member = 0;
  }

  filter1 = 1;
  filter2 = 1;
  filter3 = 1;
}

int main(int argc, char **argv) {
  int filter1_idx, filter2_idx, filter3_idx, member, filter1, filter2, filter3;
  std::cout << "input the initial value of p.filter1_idx: " << std::endl;
  std::cin >> filter1_idx;
  std::cout << "input the initial value of p.filter2_idx: " << std::endl;
  std::cin >> filter2_idx;
  std::cout << "input the initial value of p.filter3_idx: " << std::endl;
  std::cin >> filter3_idx;
  std::cout << "input the initial value of p.member: " << std::endl;
  std::cin >> member;
  std::cout << "input the initial value of filter1: " << std::endl;
  std::cin >> filter1;
  std::cout << "input the initial value of filter2: " << std::endl;
  std::cin >> filter2;
  std::cout << "input the initial value of filter3: " << std::endl;
  std::cin >> filter3;

  // Run domino func
  learn_filter(filter1_idx, filter2_idx, filter3_idx, member, filter1, filter2, filter3);

  std::cout << "The updated values of p.filter1_idx, p.filter2_idx, p.filter3_idx, p.member, filter1, filter2 and filter3 are " << filter1_idx  << ", " << filter2_idx << ", " << filter3_idx << ", " << member << ", " << filter1 << ", " << filter2 << ", " << filter3 << std::endl;
  return 0;
}
