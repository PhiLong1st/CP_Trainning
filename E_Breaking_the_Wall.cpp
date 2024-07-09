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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << (a[1] + 1) / 2;
        return;
    }
    int ans = INF;
    for (int i = 1; i < n; i++)
    {
        if (min(a[i], a[i + 1]) * 2 <= max(a[i], a[i + 1]))
        {
            ans = min(ans, (max(a[i], a[i + 1]) + 1) / 2);
        }
        else
        {
            ans = min(ans, (a[i] + a[i + 1] + 2) / 3);
        }
    }
    for (int i = 1; i < n - 1; i++)
    {
        ans = min(ans, a[i] / 2 + a[i + 2] / 2 + ((a[i] % 2) + (a[i + 2] % 2) + 1) / 2);
    }
    sort(a.begin() + 1, a.end());
    for (int i = 1; i < n; i++)
    {
        ans = min(ans, (a[i] + 1) / 2 + (a[i + 1] + 1) / 2);
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