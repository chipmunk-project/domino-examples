#include <iostream>
#define NUM_FLOWS 8000
#define TIME_MIN 1

void stfq(int &id, int &start, int &virtual_time, int &length, int &last_finish) {
  id  = id; 
  if ((last_finish > TIME_MIN) && (virtual_time < last_finish)) {
    start = last_finish;
    last_finish += length;
  } else {
    start = virtual_time;
    last_finish = virtual_time + length;
  }
}

int main(int argc, char **argv) {
  int id, start, virtual_time, length, last_finish;
  std::cout << "input the initial value of p.id: " << std::endl;
  std::cin >> id;
  std::cout << "input the initial value of p.start: " << std::endl;
  std::cin >> start;
  std::cout << "input the initial value of p.virtual_time: " << std::endl;
  std::cin >> virtual_time;
  std::cout << "input the initial value of p.length: " << std::endl;
  std::cin >> length;
  std::cout << "input the initial value of last_finish: " << std::endl;
  std::cin >> last_finish;

  // Run domino func
  stfq(id, start, virtual_time, length, last_finish);

  std::cout << "The updated values of p.id, p.start, p.virtual_time, p.length and last_finish are " << id << ", " << start << ", " << virtual_time << ", " << length << ", " << last_finish << std::endl;
  return 0;
}
