#include <iostream>
#include <vector>
using namespace std;
int main()
{
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int k, n;
    cin >> k >> n;
    vector<vector<int>> v(k, vector<int>(n));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    int consistent = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int timesjwasbetter = 0;
            for (int l = 0; l < k; l++)
            {
                for (int h = 0; h < n; h++)
                {
                    if (v[l][h] == j)
                    {
                        timesjwasbetter++;
                        break;
                    }
                    else if (v[l][h] == i)
                    {
                        break;
                    }
                }
            }
            if (timesjwasbetter == k || timesjwasbetter == 0)
            {
                consistent++;
            }
        }
    }
    cout << consistent;
}

//do using adj from graph