#include <iostream>
using namespace std;
int main() {
  int p, c;
  cin >> p >> c;
  int score = 0;
  score += p * 50;
  score -= c * 10;
  if (p > c) {
    score += 500;
  }
  cout << score;
}