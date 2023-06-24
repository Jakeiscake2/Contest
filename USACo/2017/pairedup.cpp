#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {


    freopen("pairup.in","r",stdin);
    freopen("pairup.out","w",stdout);
  
  int lines;
  cin >> lines;

  vector<int> cows;
  for (int i = 0; i < lines; i++) {
    int number, milk;
    cin >> number >> milk;
    vector<int> add(number, milk);
    cows.insert(cows.end(),add.begin(),add.end());
  }

  sort(cows.begin(), cows.end());

  int longest = 0,num_cows=cows.size();
  for (int pointer = 0; pointer <= num_cows/2; pointer++) {
    longest = max(longest, cows[pointer] + cows[num_cows - pointer - 1]);
  }
  cout<<longest;
 }

 // vector of pairs for better mem
 