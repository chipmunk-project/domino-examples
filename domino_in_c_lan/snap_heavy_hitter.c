#include <iostream>
#define THRESHOLD 1000

// SNAP policy 7
// Triggered only when tcp.flags = SYN (that's the guard)
void snap_heavy_hitter(int &srcip, int &heavy_hitter, int &hh_counter) {
  // TODO: Domino compiler bug
  srcip = srcip;

  if (heavy_hitter == 0) {
    hh_counter = hh_counter + 1;
    if (hh_counter == THRESHOLD) {
      heavy_hitter = 1;
    }
  }
}

int main(int argc, char **argv) {
  int srcip, heavy_hitter, hh_counter;
  std::cout << "input the initial value of p.srcip: " << std::endl;
  std::cin >> srcip;
  std::cout << "input the initial value of heavy_hitter: " << std::endl;
  std::cin >> heavy_hitter;
  std::cout << "input the initial value of hh_counter: " << std::endl;
  std::cin >> hh_counter;

  // Run domino func
  snap_heavy_hitter(srcip, heavy_hitter, hh_counter);

  std::cout << "The updated values of p.srcip, heavy_hitter and hh_counter are " << srcip << ", " << heavy_hitter << ", " << hh_counter << std::endl;
  return 0;
}
