#include <iostream>
#define MAX_ALLOWABLE_RTT 30

void rcp(int &rtt, int &size_bytes, int &input_traffic_Bytes, int &sum_rtt_Tr, int &num_pkts_with_rtt) {
  input_traffic_Bytes += size_bytes;
  if (rtt < MAX_ALLOWABLE_RTT) {
    sum_rtt_Tr += rtt;
    num_pkts_with_rtt += 1;
  }
}

int main(int argc, char **argv) {
  int rtt, size_bytes, input_traffic_Bytes, sum_rtt_Tr, num_pkts_with_rtt;
  std::cout << "input the initial value of p.rtt: " << std::endl;
  std::cin >> rtt;
  std::cout << "input the initial value of p.size_bytes: " << std::endl;
  std::cin >> size_bytes;
  std::cout << "input the initial value of input_traffic_Bytes: " << std::endl;
  std::cin >> input_traffic_Bytes;
  std::cout << "input the initial value of sum_rtt_Tr: " << std::endl;
  std::cin >> sum_rtt_Tr;
  std::cout << "input the initial value of num_pkts_with_rtt: " << std::endl;
  std::cin >> num_pkts_with_rtt;

  // Run domino func
  rcp(rtt, size_bytes, input_traffic_Bytes, sum_rtt_Tr, num_pkts_with_rtt);

  std::cout << "The updated values of p.rtt, p.size_bytes, input_traffic_Bytes, sum_rtt_Tr and num_pkts_with_rtt are " << rtt << ", " << size_bytes << ", " << input_traffic_Bytes << ", " << sum_rtt_Tr << ", " << num_pkts_with_rtt  << ", " << std::endl;
  return 0;
}
