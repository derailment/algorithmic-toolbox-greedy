#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int res = n;
  for(int i=1; i<=n; i++) {
    int tryRes = res - i;
    if (tryRes == 0) {
      summands.push_back(i);
      break;
    } else {
      if (tryRes - (i + 1) >= 0) {
        summands.push_back(i);
        res = tryRes;
      } 
    }
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
