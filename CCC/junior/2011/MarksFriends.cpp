// Unfriend
#include <iostream>
#include <vector>
using namespace std;

int remove(vector<vector<int>> &v,int current) {
  if (v[current].size() == 0) {
    return 2;
  }
  int sum = 1;
  for (int f : v[current]) {
      sum*=(remove(v,f));
  }
  if (current != v.size() - 1) {
    sum+=1;
  }
  return sum;
}


int main() {
  int n;
  cin >> n;
  vector<vector<int>> v(n+1);
  for (int i = 1; i < n ; i++) {
    int new_friend;
    cin >> new_friend;
    v[new_friend].push_back(i);
  }
  cout<<remove(v, n);
}