#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct movesTime {
  int x, y, moves;
};

bool visted[9][9];
queue<movesTime> q;

void addPoint(int x, int y, int moves) {
  if (x > 8 || y > 8 || x <= 0 || y <= 0) {
    return;
  }
  if (visted[x][y]) {
    return;
  }
  visted[x][y] = true;
  q.push({x, y, moves + 1});
}

int main() {
  movesTime start;
  pair<int, int> end;
  cin >> start.x >> start.y;
  start.moves = 0;
  cin >> end.first >> end.second;

  visted[start.x][start.y] = true;
  q.push(start);
  while (!q.empty()) {
    movesTime cords = q.front();
    visted[cords.x][cords.y] = true;
    q.pop();
    if (cords.x == end.first && cords.y == end.second) {
      cout << cords.moves << endl;
      break;
    }
    addPoint(cords.x + 1, cords.y + 2, cords.moves);
    addPoint(cords.x + 2, cords.y + 1, cords.moves);
    addPoint(cords.x - 1, cords.y + 2, cords.moves);
    addPoint(cords.x + 2, cords.y - 1, cords.moves);
    addPoint(cords.x - 1, cords.y - 2, cords.moves);
    addPoint(cords.x - 2, cords.y - 1, cords.moves);
    addPoint(cords.x + 1, cords.y - 2, cords.moves);
    addPoint(cords.x - 2, cords.y + 1, cords.moves);
  }
}
