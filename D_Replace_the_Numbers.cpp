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
    int q;
    cin >> q;
    vector<int> t(q + 1), x(q + 1), y(q + 1);
    int numVec = 0;
    for (int i = 1; i <= q; i++)
    {
        cin >> t[i] >> x[i];
        if (t[i] == 2)
            cin >> y[i];
    }
    vector<int> f(5e5 + 1), ans;
    iota(f.begin(), f.end(), 0);
    for (int i = q; i >= 1; --i)
    {
        if (t[i] == 1)
        {
            ans.push_back(f[x[i]]);
        }
        else
        {
            f[x[i]] = f[y[i]];
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans)
    {
        cout << i << " ";
    }
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