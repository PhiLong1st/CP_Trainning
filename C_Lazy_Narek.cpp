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
    vector<string> s(n + 1), t(n + 1), pre(n + 1), suf(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int l = -1, r = -1;
        string tmp = "narek";
        int dem = 0;
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == tmp[dem])
            {
                if (l == -1)
                {
                    l = j;
                }
                dem++;
                if (dem == 5)
                {
                    r = j;
                    dem = 0;
                }
            }
        }
        if (l == -1 || r == -1)
        {
            pre[i] = suf[i] = s[i];
        }
        else
        {
            pre[i] = s[i].substr(0, l);
            string tmpStr = s[i];
            reverse(tmpStr.begin(), tmpStr.end());
            suf[i] = tmpStr.substr(0, m - r - 1);
            reverse(suf[i].begin(), suf[i].end());
        }
        cout << l << " " << pre[i] << " " << r << " " << suf[i] << "\n";
    }
    vector<int> dp(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
        }
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