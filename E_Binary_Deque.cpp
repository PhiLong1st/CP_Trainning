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
    int n, sum;
    cin >> n >> sum;
    vector<int> a(n + 1), d(n + 1), check(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[i] = d[i - 1] + a[i];
    }
    int ans = -1;
    check[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] != 0 && check[d[i]] == 0)
        {
            check[d[i]] = i;
        }
        if (d[i] < sum)
            continue;
        ans = max(ans, i - check[d[i] - sum]);
    }
    if (ans == -1)
    {
        cout << -1 << "\n";
        return;
    }
    else
    {
        cout << n - ans << "\n";
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