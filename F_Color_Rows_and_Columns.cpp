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
    int n, k;
    cin >> n >> k;
    vector<pll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    vector2d(dp, n + 1, k + 1, int, INF);
    vector2d(cal, n + 1, k + 1, int, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= min(k, a[i].first + a[i].second); j++)
        {
            int tmpA = a[i].first, tmpB = a[i].second;
            int dem = 0, times = 0;
            while (dem < j && (tmpA != 0 || tmpB != 0))
            {
                if (tmpA <= tmpB)
                {
                    times += tmpA;
                    tmpB--;
                }
                else
                {
                    times += tmpB;
                    tmpA--;
                }
                dem++;
            }
            cal[i][j] = times;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j];
            for (int u = 1; u <= min(j, a[i].first + a[i].second); u++)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - u] + cal[i][u]);
            }
        }
    }
    if (dp[n][k] == INF)
    {
        dp[n][k] = -1;
    }
    cout << dp[n][k] << "\n";
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