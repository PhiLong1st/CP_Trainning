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
    vector<string> a(2);
    cin >> a[0] >> a[1];
    int sta = 0, end = n;
    for (int i = 0; i < n; i++)
    {
        if (a[0][i] == 'x' && a[1][i] == 'x')
        {
            continue;
        }
        sta = i;
        break;
    }
    while (n > 0 && a[0][n - 1] == 'x' && a[1][n - 1] == 'x')
    {
        n--;
    }
    int ans = 0;
    for (int i = sta + 1; i < n - 1; i++)
    {
        ans += (a[0][i - 1] == 'x' && a[0][i + 1] == 'x' && a[1][i] == '.' && a[0][i] == '.');
        ans += (a[1][i - 1] == 'x' && a[1][i + 1] == 'x' && a[0][i] == '.' && a[1][i] == '.');
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