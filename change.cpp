#include <iostream>
#include <algorithm>
#include <limits>

const int MAX = std::numeric_limits<int>::max();

int add(int a, int b) {
  if (a == MAX || b == MAX) {
      return MAX;
  } else {
    return a + b;
  }
}

int get_change(int m) {
  int denominations[3] = {1, 5, 10};
  int f[m+1];
  for (int i = 0; i <= m; i++) {
    if (i == 0) {
      f[i] = 0;
    } else if (i == 1) {
      f[i] = 1;
    } else if (i == 5) {
      f[i] = 1;
    } else if (i == 10) {
      f[i] = 1;
    } else {
      int a = i - 1 >= 0 ? add(f[i-1], 1) : MAX;
      int b = i - 5 >= 0 ? add(f[i-5], 1) : MAX;
      int c = i - 10 >= 0 ? add(f[i-10], 1) : MAX;
      int likely[3] = {a, b, c};
      f[i] = *std::min_element(likely, likely+3); 
    }
  }
  return f[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

