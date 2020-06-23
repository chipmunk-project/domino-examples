#include <iostream>

void conga(int &best_path_util_idx, int &best_path_idx, int &util, int &path_id, int &best_path_util, int &best_path) {
  best_path_util_idx = best_path_util_idx;
  best_path_idx      = best_path_idx;
  if (util < best_path_util) {
    best_path_util = util;
    best_path = path_id;
  } else if (path_id == best_path) {
    best_path_util = util;
    // TODO: I guess we aren't switching to another path in
    // case the utilization on the best path went up.
  }
}

// Also, CONGA has multiple transactions, while we are only dealing with
// the hardest of these transactions here.

int main(int argc, char **argv) {
  int best_path_util_idx, best_path_idx, util, path_id, best_path_util, best_path;
  std::cout << "input the initial value of p.best_path_util_idx: " << std::endl;
  std::cin >> best_path_util_idx;
  std::cout << "input the initial value of p.best_path_idx: " << std::endl;
  std::cin >> best_path_idx;
  std::cout << "input the initial value of p.util: " << std::endl;
  std::cin >> util;
  std::cout << "input the initial value of p.path_id: " << std::endl;
  std::cin >> path_id;
  std::cout << "input the initial value of best_path_util: " << std::endl;
  std::cin >> best_path_util;
  std::cout << "input the initial value of best_path: " << std::endl;
  std::cin >> best_path;

  // Run domino func
  conga(best_path_util_idx, best_path_idx, util, path_id, best_path_util, best_path);

  std::cout << "The updated values of p.best_path_util_idx, p.best_path_idx, p.util, p.path_id, best_path_util and best_path are " << best_path_util_idx << ", " << best_path_idx << ", " << util << ", " << path_id << ", " << best_path_util << ", " << best_path << std::endl;
  return 0;
}
