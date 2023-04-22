#include <iostream>
#include <vector>
using namespace std;

void output(vector<vector<char>> g) {
  for (vector<char> v : g) {
    for (char i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
  cout << endl;
}
void fillPossible(vector<vector<char>> &grid, vector<vector<char>> &stamp,
                  vector<vector<char>> &painting) {
  int gs = grid.size();
  int ss = stamp.size();
  for (int i = 0; i <= gs - ss; i++) {
    for (int j = 0; j <= gs - ss; j++) {

      bool good_stamp = true;
      for (int k = i; k < i + ss - 1; k++) {
        for (int l = j; l < j + ss - 1; l++) {
          if (stamp[k][l] == '*' && grid[k][l] == '.') {
            good_stamp = false;
            break;
          }
        }
        if (good_stamp == false) {
          break;
        }
      }
      if (good_stamp) {
        for (int k = 0; k < stamp.size(); k++) {
          for (int l = 0; l < stamp.size(); l++) {
            if (stamp[k][l] == '*') {
              painting[i+k][j+l] = stamp[k][l];
            }
          }
        }
        output(painting);
      }
    }
  }
}


int main() {

  vector<vector<char>> stamp = {{'.', '*'}, {'*', '*'}};
  vector<vector<char>> grid = {
      {'.', '*', '*'}, {'.', '*', '*'}, {'*', '*', '*'}};
  vector<vector<char>> painting(grid.size(), vector<char>(grid.size(), '.'));
  fillPossible(grid, stamp, painting);
  cout<<" done\n\n";
  output(grid);
  output(stamp);
  output(painting);
}

/*

. * *
* * *
* * *

* .
* .

*/