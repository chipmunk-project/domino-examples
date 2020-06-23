#include <iostream>

#define FREEZE_TIME 10
#define DELTA1 1
#define DELTA2 2
#define QMAX 5


void blue_increase(int &now, int &now_plus_free, int p_mark, int last_update) {
  now_plus_free = now - FREEZE_TIME;
  if (now_plus_free > last_update) {
     p_mark = p_mark - DELTA2;
     last_update = now;
  }
}

int main(int argc, char **argv) {
  int now, now_plus_free, p_mark, last_update;
  std::cout << "input the initial value of p.now: " << std::endl;
  std::cin >> now;
  std::cout << "input the initial value of p.now_plus_free: " << std::endl;
  std::cin >> now_plus_free;
  std::cout << "input the initial value of p_mark: " << std::endl;
  std::cin >> p_mark;
  std::cout << "input the initial value of last_update: " << std::endl;
  std::cin >> last_update;

  // Run domino func
  blue_increase(now, now_plus_free, p_mark, last_update);

  std::cout << "The updated values of p.now, p.now_plus_free, p_mark and last_update are " << now << ", " << now_plus_free << ", " << p_mark << ", " << last_update << std::endl;
  return 0;
}
