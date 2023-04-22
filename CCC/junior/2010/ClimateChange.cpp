#include <iostream>
#include <vector>
using namespace std;
int main() {
  while (true) {
    int input;
    cin >> input;
    if (input == 0) {
      cout << "0";
      break;
    }
    vector<int> array(input);
    for (int i = 1; i < input; i++) {
      cin >> array[i];
    }
    vector<int> diffs(input - 1);
    for (int i = 0; i < input - 1; i++) {
      diffs[i] = array[i] - array[i + 1];
    }
    int maxLength = 0;
    for (int i = 1; i < input - 1; i++) {
      if ((input - 1) % i != 0) {
        continue;
      }
      bool works = true;
      vector<int> loop(diffs.begin(), diffs.begin() + i);
      cout << "Loop is ";
      for (int i : loop) {
        cout << i << " ";
      }
      cout << endl;
      for (int j = 0; j < input - 1 / i; j++) {
        vector<int> IsEqualToLoop((j * ((input - 1) / i)) + diffs.begin(),
                                  (j * ((input - 1) / i)) + diffs.begin() + i);
        cout << "Check Equal is ";
        for (int i : IsEqualToLoop) {
          cout << i << " ";
        }
        cout << endl;
        if (loop != IsEqualToLoop) {
          works = false;
          break;
        }
      }
      if (works) {
        maxLength = max(maxLength, i);
      }
    }
    cout << maxLength;
  }
  return 0;
}