#include <iostream>

// Sample every 30th packet in a flow
#define N 30

void sampling(int &sample, int &count) {
  if (count == N - 1) {
    sample = 1;
    count = 0;
  } else {
    sample = 0;
    count = count + 1;
  }
}

int main(int argc, char **argv) {
  int sample, count;
  std::cout << "input the initial value of p.sample: " << std::endl;
  std::cin >> sample;
  std::cout << "input the initial value of count: " << std::endl;
  std::cin >> count;

  // Run domino func
  sampling(sample, count);

  std::cout << "The updated values of p.sample and count are " << sample  << ", " << count <<  std::endl;
  return 0;
}
