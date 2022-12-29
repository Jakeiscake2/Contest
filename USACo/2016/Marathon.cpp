#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int finddistance(pair<int, int> p1, pair<int, int> p2)
{
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
int main()
{
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
    int n = 0;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    int biggestskip = 0;
    for (int i = 0; i < v.size() - 2; i++)
    {
        int noskip, skip;
        noskip = finddistance(v[i], v[i + 1]) + finddistance(v[i + 1], v[i + 2]);
        skip = finddistance(v[i], v[i + 2]);
        biggestskip = max(noskip - skip, biggestskip);
    }
    int totaldistance = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        totaldistance += finddistance(v[i], v[i + 1]);
    }
    totaldistance -= biggestskip;
    cout << totaldistance << endl;
}