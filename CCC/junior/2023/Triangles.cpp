#include <iostream>
#include <vector>
using namespace std;
int main() {
  int c = 0;
  cin >> c;
  int tape = 0;
  int in;
  vector<int> top(c);
  vector<int> bot(c);
  for (int i = 0; i < c; i++) {
    cin >> in;
    top[i] = in;
    if (in == 1) {
      tape += 3;
    }
  }
  for (int i = 0; i < c; i++) {
    cin >> in;
    bot[i] = in;
    if (in == 1) {
      tape += 3;
    }
  }
  for (int i = 0; i < top.size() - 1; i++) {
    if (top[i] == 1 && top[i + 1] == 1) {
      tape -= 2;
    }
  }
  for (int i = 0; i < bot.size() - 1; i++) {
    if (bot[i] == 1 && bot[i + 1] == 1) {
      tape -= 2;
    }
  }
  for (int i = 0; i < top.size(); i += 2) {
    if (top[i] == 1 && bot[i] == 1) {
      tape -= 2;
    }
  }
  cout << tape;
}