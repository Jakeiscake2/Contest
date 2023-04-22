#include <iostream>
#include <vector>
using namespace std;

int main() {
  int people;
  cin >> people;
  vector<int> days(5, 0);
  char c;
  for (int i = 0; i < people; i++) {
    for (int j = 0; j < days.size(); j++) {
      cin >> c;
      if (c == 'Y') {
        days[j]++;
      }
    }
  }
  vector<int> available;
  int best = 0;
  for (int i : days) {
    best = max(best, i);
  }
  for (int i = 0; i < days.size(); i++) {
    if (days[i] == best) {
      available.push_back(i);
    }
  }
  int i = 0;
  while (true) {
    cout << available[i] + 1;
    i++;
    if (i >= available.size()) {
      break;
    }
    cout << ',';
  }
}