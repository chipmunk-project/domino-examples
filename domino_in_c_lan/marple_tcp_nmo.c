#include <iostream>

void marple_tcp_nmo(int &tcpseq, int &count, int &maxseq) {
  if (tcpseq < maxseq) {
    count = count + 1;
  } else {
    maxseq = tcpseq;
  }
}


int main(int argc, char **argv) {
  int tcpseq, count, maxseq;
  std::cout << "input the initial value of p.tcpseq: " << std::endl;
  std::cin >> tcpseq;
  std::cout << "input the initial value of count: " << std::endl;
  std::cin >> count;
  std::cout << "input the initial value of maxseq: " << std::endl;
  std::cin >> maxseq;

  // Run domino func
  marple_tcp_nmo(tcpseq, count, maxseq);

  std::cout << "The updated values of p.tcpseq, count and maxseq are " << tcpseq << ", " << count << ", " << maxseq << std::endl;
  return 0;
}
