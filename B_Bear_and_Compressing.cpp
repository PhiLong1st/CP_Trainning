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
vector<int> save;
int ans = 0, n, q;
vector<string> s, t;
void sinh(int sz, vector<int> save)
{
    if (sz == n)
    {
        // cout << save << "\n";
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << save[i] << " ";
        // }
        // cout << "\n";
        bool ok = true;
        vector<int> tmp;
        tmp = save;
        for (int i = 1; i <= n - 1; i++)
        {
            bool check = false;
            for (int j = 1; j <= q; j++)
            {
                int x = s[j][0] - 'a';
                int y = s[j][1] - 'a';
                int z = t[j][0] - 'a';
                if (x == save[i] && y == save[i + 1])
                {
                    save[i + 1] = z;
                    check = true;
                    break;
                }
            }
            if (!check)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            if (save[n] == 0)
            {
                ans++;
            }
        }
        return;
    }
    for (int i = 0; i < 6; i++)
    {
        save[sz + 1] = i;
        sinh(sz + 1, save);
    }
}
void solve()
{
    cin >> n >> q;
    s.resize(q + 1);
    t.resize(q + 1);
    save.resize(n + 1, 0);
    for (int i = 1; i <= q; i++)
    {
        cin >> s[i] >> t[i];
    }
    sinh(0, save);
    cout << ans << "\n";
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