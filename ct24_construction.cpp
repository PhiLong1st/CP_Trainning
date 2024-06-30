/*
    Code by: KoKoDuDu
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pll pair<int, int>
#define pdb pair<db, db>
#define vector2d(name, sz1, sz2, type, val) vector<vector<type>> name(sz1, vector<type>(sz2, val))
#define vector3d(name, sz1, sz2, sz3, type, val) vector<vector<vector<type>>> name(sz1, vector<vector<type>>(sz2, vector<type>(sz3, val)))
#define vector4d(name, sz1, sz2, sz3, sz4, type, val) vector<vector<vector<vector<type>>>> name(sz1, vector<vector<vector<type>>>(sz2, vector<vector<type>>(sz3, vector<type>(sz4, val))))

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve()
{
    int n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector2d(dp, n + 1, m + 1, ll, INF);
    // cout << dp[1][1] << "\n";
    dp[0][0] = 0;
    ll tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        tmp = __gcd(tmp, a[i]);
        dp[i][1] = y;
        if (tmp == k)
        {
            dp[i][1] = x;
        }
        ll gcd = a[i];
        for (int u = i; u >= 1; u--)
        {
            gcd = __gcd(gcd, a[u]);
            for (int j = 2; j <= min(i, m); j++)
            {
                int val = (gcd == k) ? x : y;
                dp[i][j] = min(dp[i][j], val + dp[u - 1][j - 1]);
            }
        }
    }
    cout << dp[n][m];
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