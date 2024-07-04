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
    vector<string> s(11);
    vector2d(a, 11, 11, int, 0);
    for (int i = 1; i <= 10; i++)
    {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    int ans = 0, l = 1, r = 10;
    for (int t = 1; t <= 5; t++)
    {
        for (int i = l; i <= r; i++)
        {
            for (int j = l; j <= r; j++)
            {
                a[i][j] = t;
            }
        }
        l++, r--;
    }
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            if (s[i][j] == 'X')
            {
                ans += a[i][j];
            }
            // cout << a[i][j] << " ";
        }
    }
    cout << ans << "\n";
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