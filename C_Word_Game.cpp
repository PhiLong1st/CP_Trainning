/*
    Code by: KoKoDuDu
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define db double
#define pll pair<int, int>
#define pdb pair<db, db>
#define vector2d(name, sz1, sz2, type, val) vector<vector<type>> name(sz1, vector<type>(sz2, val))
#define vector3d(name, sz1, sz2, sz3, type, val) vector<vector<vector<type>>> name(sz1, vector<vector<type>>(sz2, vector<type>(sz3, val)))
#define vector4d(name, sz1, sz2, sz3, sz4, type, val) vector<vector<vector<vector<type>>>> name(sz1, vector<vector<vector<type>>>(sz2, vector<vector<type>>(sz3, vector<type>(sz4, val))))

const int MOD = 1e9 + 7;
const int INF = 1e18;
void solve()
{
    int n;
    cin >> n;
    int u = 0, v = 0, w = 0;
    vector<int> ans(3);
    vector<vector<string>> a(3, vector<string>(n));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    map<string, int> save;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            save[a[j][i]]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (save[a[j][i]] == 1)
            {
                ans[j] += 3;
            }
            if (save[a[j][i]] == 2)
            {
                ans[j] += 1;
            }
        }
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    cin >> numTest;
    while (numTest--)
    {
        solve();
    }
    return 0;
}