#include <iostream>

void dns_ttl_change(int &id, int &rdata, int &ttl, int &seen, int &last_ttl, int &ttl_change) {
  id = rdata;
  if (seen == 0) {
    seen = 1;
    last_ttl = ttl;
    ttl_change = 0;
  }
  else {
    if (last_ttl != ttl) {
      last_ttl = ttl;
      ttl_change += 1;
    }
  }
}

int main(int argc, char **argv) {
  int id, rdata, ttl, seen, last_ttl, ttl_change;
  std::cout << "input the initial value of p.id: " << std::endl;
  std::cin >> id;
  std::cout << "input the initial value of p.rdata: " << std::endl;
  std::cin >> rdata;
  std::cout << "input the initial value of p.ttl: " << std::endl;
  std::cin >> ttl;
  std::cout << "input the initial value of seen: " << std::endl;
  std::cin >> seen;
  std::cout << "input the initial value of last_ttl: " << std::endl;
  std::cin >> last_ttl;
  std::cout << "input the initial value of ttl_change: " << std::endl;
  std::cin >> ttl_change;

  // Run domino func
  dns_ttl_change(id, rdata, ttl, seen, last_ttl, ttl_change);

  std::cout << "The updated values of p.id, p.rdata, p.ttl, seen, last_ttl and ttl_change are " << id << ", " << rdata << ", " << ttl << ", " << seen << ", " << last_ttl << ", " << ttl_change << std::endl;
  return 0;
}
