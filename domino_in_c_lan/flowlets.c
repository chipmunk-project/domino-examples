#include <iostream>

#define NUM_FLOWLETS 8000
#define THRESHOLD    5
#define NUM_HOPS     10

struct Packet {
  int new_hop;
  int arrival;
  int next_hop;
  int id; // array index
};

int last_time [NUM_FLOWLETS] = {0};
int saved_hop [NUM_FLOWLETS] = {0};

void flowlets(int &new_hop, int &id, int &arrival, int &next_hop, int &last_time, int &saved_hop) {
  new_hop = new_hop;
  id  = id;
  if (arrival - last_time > THRESHOLD) {
    saved_hop = new_hop;
  }
  last_time = arrival;
  next_hop = saved_hop;
}

int main(int argc, char **argv) {
    
    int new_hop, id, arrival, next_hop, last_time, saved_hop;
    std::cout << "input the initial value of p.new_hop: " << std::endl;
    std::cin >> new_hop;
    std::cout << "input the initial value of p.id: " << std::endl;
    std::cin >> id;
    std::cout << "input the initial value of p.arrival: " << std::endl;
    std::cin >> arrival;
    std::cout << "input the initial value of p.next_hop: " << std::endl;
    std::cin >> next_hop;
    std::cout << "input the initial value of last_time: " << std::endl;
    std::cin >> last_time;
    std::cout << "input the initial value of saved_hop: " << std::endl;
    std::cin >> saved_hop;

    flowlets(new_hop, id, arrival, next_hop, last_time, saved_hop);
    std::cout << "The updated values of p.new_hop, p.id, p.arrival, p.next_hop, last_time and saved_hop are " << new_hop << ", " << id << ", " << arrival << ", " << next_hop << ", " << last_time << ", " << saved_hop << std::endl;
    return 0;
}
