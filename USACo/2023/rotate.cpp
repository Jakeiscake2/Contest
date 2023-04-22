#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<char>> &stamp) {
  int ss = stamp.size();
  vector<vector<char>> new_stamp(ss, vector<char>(ss));
  for (int i = 0; i < ss; i++) {
    for (int j = 0; j < ss; j++) {
      new_stamp[ss - 1 - i][j] = stamp[j][i];
    }
  }
  stamp = new_stamp;
}

int main() {
  vector<vector<char>> stamp = {
      {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
  for (vector<char> v : stamp) {
    for (char i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
  rotate(stamp);
  cout << endl;
  for (vector<char> v : stamp) {
    for (char i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
}
