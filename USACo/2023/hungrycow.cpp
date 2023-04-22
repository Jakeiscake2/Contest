#include <iostream>
using namespace std;
int main() {
  long long n, t;
  cin >> n >> t;
  long long eaten = 0;
  long long haybales = 0;
  long long last_day = 0;
    t+=1;
  for (long long i = 0; i < n; i++) {
    long long day, recieved;
    cin >> day >> recieved;
    long long time_between = day - last_day;

    if (haybales < time_between) {
      eaten += haybales;
      haybales = 0;
    } else {
      haybales -= time_between;
      eaten += time_between;
    }
    last_day=day;
    haybales += recieved;
  }
//t = 5
//hay = 10


  if (haybales > 0 && last_day < t) {
    eaten += min(haybales,(t-last_day));
  }
  if (eaten > t) {
    eaten = t;
  }
  cout << eaten;
}

/*
1 2 3 4 5 6 7 8 9 1 2 3
. . . . . . . . . . . .
2   4   2     D   4
0 0 0 0 0 0 0 0   0 0 0

8






*/