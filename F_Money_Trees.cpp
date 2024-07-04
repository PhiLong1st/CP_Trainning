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
    vector<int> h(n + 1), dp(n + 1, 1), sum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    for (int i = n - 1; i >= 1; i--)
    {
        if (h[i] % h[i + 1] == 0)
        {
            dp[i] += dp[i + 1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int res = 0;
        // cout << dp[i] << " ";
        int l = i;
        int r = i + dp[i] - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            int val = sum[mid] - sum[i - 1];
            if (val <= k)
            {
                res = mid - i + 1;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        ans = max(ans, res);
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