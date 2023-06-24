#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool tryBuses(vector<int> &v, int m, int c, int t) {
  int waiting = v[0];
  int buses_used = 0;
  int bus_spots = 0;
  for (int i = 0; i < v.size(); i++) {
    if (bus_spots == c || v[i] - waiting > t) {
      buses_used++;
      if (buses_used > m) {
        return false;
      }
      bus_spots = 0;
      waiting = v[i];
    }
    bus_spots++;
  }
  if (bus_spots > 0 && m == buses_used) {
    return false;
  }
  return true;
}

int main() {

   freopen("convention.in","r",stdin);
   freopen("convention.out","w",stdout);
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> v(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int low=0,high=v[v.size()-1]-v[0];
  while(low<high){
    int middle=(low+high)/2;
    if(tryBuses(v, m, c, middle)){
        high=middle;
    }
    else{
        low=middle+1;
    }
  }
  cout<<high;
}