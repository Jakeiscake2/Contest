#include <iostream>
#include <vector>
#include <queue>
#include<map>
using namespace std;
string word;

//use queue

struct check{
    int col;
    int row;
    int driection;
    bool chagned;
    int letter;
};



int main() {
  int found=0;
  int r, c;
  cin >> word >> r >> c;
  vector<pair<int, int>> m;
  queue<check> q;
  vector<vector<char>> v(r, vector<char>(c));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin>>v[i][j];
      if (v[i][j] == word[0]) {
        m.push_back({i,j});
      }
    }
  }
  for (pair<int, int> p: m) {
    q.push({p.first,p.second,1,false,0});
    q.push({p.first,p.second,2,false,0});
    q.push({p.first,p.second,3,false,0});
    q.push({p.first,p.second,4,false,0});
    q.push({p.first,p.second,5,false,0});
    q.push({p.first,p.second,6,false,0});
    q.push({p.first,p.second,7,false,0});
    q.push({p.first,p.second,8,false,0});
  }
    map<int,pair<int,int>> direct;
  while (!q.empty()) {
    check current = q.front();
    char next_letter = word[current.letter+1];
    q.pop();
    if (v[current.col+direct[current.driection].first][current.row+direct[current.driection].second] !=next_letter) {
      continue;
    }
    current.letter++;
    q.push(current);
    if (current.chagned) {
      continue;
    }
    if (v[current.col - 1][current.row - 1] == next_letter) {
    current.driection = 1;
    current.chagned = true;
    q.push(current);
    current.chagned = false;
    }
    if (v[current.col -1][current.row + 0] == next_letter) {
    current.driection = 2;
    current.chagned = true;
    q.push(current);
    current.chagned = false;
    }
    if (v[current.col - 1][current.row + 1] == next_letter) {
    current.driection = 3;
    current.chagned = true;
    q.push(current);
    current.chagned = false;
    }
    if (v[current.col + 0][current.row - 1] == next_letter) {
    current.driection = 4;
    current.chagned = true;
    q.push(current);
    current.chagned = false;
    }
    if (v[current.col + 0][current.row + 1] == next_letter) {
    current.driection = 5;
    current.chagned = true;
    q.push(current);
    current.chagned = false;
    }
    if (v[current.col + 1][current.row - 1] == next_letter) {
    current.driection = 6;
    current.chagned = true;
    q.push(current);
    current.chagned = false;
    }
    if (v[current.col + 1][current.row + 0] == next_letter) {
    current.driection = 7;
    current.chagned = true;
    q.push(current);
    current.chagned = false;
    }
    if (v[current.col + 1][current.row + 1] == next_letter) {
    current.driection = 8;
    current.chagned = true;
    q.push(current);
    current.chagned = false;
    }
    
  }
  cout<<found;
}

/*
MENU 5 7
F T R U B L K
P M N A X C U
A E R C N E O
M N E U A R M
M U N E M N S
*/


/*
1 2 3
4 0 5
6 7 8
*/