#include <climits>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool canDance(vector<int> &v, int t, int k) {
  vector<int> stage(k);
  int next = 0;
  if (k > v.size()) {
    int big = 0;
    for (int i : v) {
      big = max(big, i);
    }
    return t >= big;
  }
  int current_time = 0;
  for (; next < k; next++) {
    stage[next] = v[next];
  }
  while (next < v.size()) {
    int small = INT_MAX;
    for (int i : stage) {
      small = min(small, i);
    }
    current_time = small;
    for (int i = 0; i < stage.size(); i++) {
      if (stage[i] <= current_time) {
        stage[i] = v[next]+current_time;
        next++;
      }
    }
  }
  int big=0;
  for (int i : stage) {
    big = max(big, i);
  }
  current_time=max(big,current_time);
  return current_time<=t;
}

int main() {
  freopen("cowdance.in","r",stdin);
  freopen("cowdance.out","w",stdout);
  int n, t;
  cin >> n >> t;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int low = 1, high = n;

  while (low < high) {
    int middle = (low + high) / 2;
    if (canDance(v, t, middle)) {
      high = middle;
    } else {
      low = middle + 1;
    }
  }
  cout << high;
}