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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> b(n + 1, vector<int>(m + 1));
    vector<int> a(n + 2), dp(n + 2, -INF);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 1; j <= min(m, n - i + 1); j++)
        {
            cin >> b[i][j];
        }
    }
    dp[1] = -a[1];
    for (int i = 2; i <= n + 1; i++)
    {
        for (int j = max(1LL, i - m); j < i; j++)
        {
            dp[i] = max(dp[i], dp[j] + b[j][i - j] - a[i]);
        }
    }
    cout << -dp[n + 1];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    while (numTest--)
    {
        solve();
    }
    return 0;
}