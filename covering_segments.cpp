#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool comp(Segment a, Segment b) {
  if (a.end < b.end) {
    return true;
  } 
  return false;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  vector<int> results;
  std::sort(segments.begin(), segments.end(), comp);
  while(segments.size() != 0) {
    int minEnd = segments[0].end;
    if (segments.size() == 1) {
      results.push_back(minEnd);
      segments.erase(segments.begin());
      break;
    }
    for (int i = 0; i < segments.size(); i++) {
      if (i == (segments.size() - 1) && segments[i].start <= minEnd) {
        results.push_back(minEnd);
        segments.erase(segments.begin(), segments.begin() + segments.size());
        break;
      } else if (segments[i].start <= minEnd) {
        continue;
      } else {
        results.push_back(minEnd);
        segments.erase(segments.begin(), segments.begin() + i);
        break;
      }
    }
  }
  for (size_t i = 0; i < results.size(); ++i) {
    points.push_back(results[i]);
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
