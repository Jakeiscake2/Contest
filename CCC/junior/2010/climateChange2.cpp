#include <iostream>
#include <vector>
using namespace std;

bool testCycles(vector<int> &diffs, int length) {
  for (int i = 0; i < diffs.size() - length; i++) {
    if (diffs[i] != diffs[i + length]) {
      return false;
    }
  }
  return true;
}

int main() {
  while (true) {
    int input;
    cin >> input;
    if (input == 0) {
      break;
    } else if (input == 1) {
      cout<< 0<<endl;
    }
    vector<int> array(input);
    for (int i = 0; i < input; i++) {
      cin >> array[i];
    }
    vector<int> diffs(input - 1);
    for (int i = 0; i < input - 1; i++) {
      diffs[i] = array[i] - array[i + 1];
    }
    for (int i = 1; i <= diffs.size(); i++) {
      if (testCycles(diffs, i)) {
        cout << i << endl;
        break;
      }
    }
  }
}
// 1,2,-2,1,2,-2
//3< 6-3