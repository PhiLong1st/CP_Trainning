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
const int maxN = 4e3 + 0307;
int a[maxN], dp[maxN][maxN];
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int minn, maxx;
        maxx = minn = a[i];
        for (int j = 1; j <= n; j++)
        {
            if (j - i + 1 >= 3 && i < j)
            {
                int tmp = (a[i - 1] * a[j - 1] >= 0 ? maxx : minn);
                dp[i][j] += dp[i][j - 1] + dp[i - 1][j] + a[i - 1] * a[j - 1] * tmp - dp[i - 1][j - 1];
                maxx = max(maxx, a[j - 1]);
                minn = min(minn, a[j - 1]);
                continue;
            }
            dp[i][j] += dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
        }
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << dp[r][r] - dp[r][l - 1] - dp[l - 1][r] + dp[l - 1][l - 1] << "\n";
    }
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