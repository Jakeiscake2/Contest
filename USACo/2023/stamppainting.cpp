#include <iostream>
#include <vector>
using namespace std;

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
              painting[i + k][j + l] = stamp[k][l];
            }
          }
        }
      }
    }
  }
}

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

string possible(int gs, int ss, vector<vector<char>> &grid,
                vector<vector<char>> &stamp) {
  vector<vector<char>> painting(gs, vector<char>(gs, '.'));

  fillPossible(grid, stamp, painting);
  rotate(stamp);
  fillPossible(grid, stamp, painting);
  rotate(stamp);
  fillPossible(grid, stamp, painting);
  rotate(stamp);
  fillPossible(grid, stamp, painting);
  rotate(stamp);
  if (painting == grid) {
    return "YES";
  } else {
    return "FALSE";
  }
}

int main() {
  int testcases;
  cin >> testcases;
  vector<string> output(testcases);
  for (int i = 0; i < testcases; i++) {
    int g_size, stamp_size;
    cin >> g_size;
    vector<vector<char>> grid(g_size, vector<char>(g_size));
    for (int j = 0; j < g_size; j++) {
      for (int k = 0; k < g_size; k++) {
        cin >> grid[j][k];
      }
    }
    cin >> stamp_size;
    vector<vector<char>> stamp(stamp_size, vector<char>(stamp_size));
    for (int j = 0; j < stamp_size; j++) {
      for (int k = 0; k < stamp_size; k++) {
        cin >> stamp[j][k];
      }
    }
    output[i] = possible(g_size, stamp_size, grid, stamp);
  }
  for (string s : output) {
    cout << s << endl;
  }
}

/*
1 2 3
4 5 6
7 8 9

7 4 1
8 5 2
9 6 3

1 2
3 4

3 1
2 4

1 2 3 4
5 6 7 8
9 0 1 2
3 4 5 6

3 9 5 1
4 0 6 2
5 1 7 3
6 2 8 4

[0][0]=[0][3]
[0][1]=[1][3]
[0][2]=[2][3]

[1][0]=[0][2]
[1][1]=[1][2]


4

2
**
*.
1
*

3
.**
.**
***
2
.*
**

3
...
.*.
...
3
.*.
...
...

3
**.
.**
..*
2
.*
*.


*/