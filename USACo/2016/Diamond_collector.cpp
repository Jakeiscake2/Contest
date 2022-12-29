#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int mostdiamonds = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int diamonds = 0;

        for (int j = 0; j < v.size(); j++)
        {
            if (v[i] <= v[j] && v[i] + k >= v[j])
            {
                diamonds++;
            }
        }
        mostdiamonds = max(diamonds, mostdiamonds);
    }
    cout << mostdiamonds;
}