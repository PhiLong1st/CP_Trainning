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
    int s, n;
    cin >> s >> n;
    if (s == (1LL << n) - 1)
    {
        cout << 0 << "\n";
        return;
    }
    if (s > (1LL << n) - 1)
    {
        cout << -1 << "\n";
        return;
    }
    int du = ((1LL << n) - s) / 2LL;
    int ans = 0;
    // cout << du << " ";
    // if (du == 2)
    // {
    //     cout << 3 << "\n";
    //     return;
    // }
    for (int bit = 60; bit >= 0; bit--)
    {
        if ((du & (1LL << bit)) != 0)
        {
            // cout << bit << " ";
            ans += (1LL << (bit + 1)) - 1;
            while (bit >= 0 && (du & (1LL << bit)) != 0)
            {
                // // cout << bit << " ";
                // ans += (1 << (bit + 1)) - 1;
                // // cout << ans << " ";
                bit--;
            }
            if (bit >= 0)
            {
                ans += (1LL << (bit + 1)) - 1;
            }
        }
    }
    if (((du & 2) != 0) & (((du & 1) == 0)))
    {
        ans--;
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