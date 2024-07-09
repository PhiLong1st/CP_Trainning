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
    string s;
    cin >> s;
    int sz = s.size();
    if (sz <= 8)
    {

        int ans = 0;
        for (int mask = 0; mask < (1 << sz); mask++)
        {
            int val = __builtin_popcount(mask) % 2;
            if (val)
                continue;
            string tmp = "";
            for (int i = 0; i < sz; i++)
            {
                if ((mask & (1 << i)))
                {
                    tmp += s[i];
                }
            }
            bool check = false;
            bool valid = true;
            for (int i = 0; i < tmp.size(); i += 2)
            {
                if (tmp[i] == 'K' && tmp[i + 1] == 'K')
                {
                    valid = false;
                    break;
                }
                if (tmp[i] == 'O' && tmp[i + 1] == 'O')
                {
                    valid = false;
                    break;
                }
            }
            if (!valid)
                continue;
            for (int i = 0; i < tmp.size(); i += 2)
            {
                if (tmp[i] == 'O' && tmp[i + 1] == 'K')
                {
                    check ^= false;
                }
                if (tmp[i] == 'K' && tmp[i + 1] == 'O')
                {
                    check ^= true;
                }
            }
            ans += !check;
        }
        cout << ans << "\n";
        return;
    }
    vector3d(dp, sz + 1, 3, 2, int, 0);
    dp[sz - 1][2][1] = 1;
    int type = (s[sz - 1] == 'K');
    dp[sz - 1][type][1] = 1;
    for (int i = sz - 2; i >= 0; i--)
    {
        if (s[i] == 'O')
        {
            for (int j = 0; j <= 1; j++)
            {
                dp[i][0][j] = (dp[i + 1][2][j] + dp[i + 1][0][j]) % MOD;
                dp[i][2][j] = (dp[i + 1][2][j] + dp[i + 1][1][j]) % MOD;
                dp[i][1][j] = dp[i + 1][1][j];
            }
        }
        else
        {
            for (int j = 0; j <= 1; j++)
            {
                dp[i][2][j] = (dp[i + 1][2][j] + dp[i + 1][0][1LL - j]) % MOD;
                dp[i][1][j] = (dp[i + 1][2][j] + dp[i + 1][1][j]) % MOD;
                dp[i][0][j] = dp[i + 1][0][j];
            }
        }
    }
    cout << dp[0][2][1] << "\n";
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