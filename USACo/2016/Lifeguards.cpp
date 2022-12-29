#include <iostream>
#include <vector>
using namespace std;
int main()
{
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n = 0;
    cin >> n;
    vector<pair<int, int>> v(n);
    vector<int> arr(1001, 0);
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start;
        cin >> end;
        v[i].first = start;
        v[i].second = end;
        for (int j = start + 1; j <= end; j++)
        {
            arr[j]++;
        }
    }
    int mosttime = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int timecovered = 0;
        for (int j = v[i].first + 1; j <= v[i].second; j++)
        {
            arr[j]--;
        }

        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] >= 1)
            {
                timecovered++;
            }
        }
        for (int j = v[i].first + 1; j <= v[i].second; j++)
        {
            arr[j]++;
        }
        mosttime = max(mosttime, timecovered);
    }
    cout << mosttime << endl;
}