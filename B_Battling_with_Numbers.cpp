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

const int MOD = 998244353;
const int INF = 1e18;
void solve()
{
    int n, m;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    map<int, int> checkA, checkB;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        checkA[a[i]] = b[i];
    }
    cin >> m;
    vector<int> c(m + 1), d(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> d[i];
    }
    for (int i = 1; i <= m; i++)
    {
        if (checkA[c[i]] < d[i])
        {
            cout << 0 << "\n";
            return;
        }
        checkA[c[i]] -= d[i];
    }
    int dem = 0;
    for (int i = 1; i <= n; i++)
    {
        if (checkA[a[i]] > 0)
        {
            dem++;
        }
    }
    int ans = 1;
    for (int i = 1; i <= dem; i++)
    {
        ans *= 2;
        ans %= MOD;
    }
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