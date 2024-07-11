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
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
struct info
{
    int x, y, du;
    info(int _x, int _y, int _du)
    {
        x = _x;
        y = _y;
        du = _du;
    }

    info()
    {
    }
    bool operator<(const info &other) const
    {
        if (x != other.x)
            return x < other.x;
        if (y != other.y)
            return y < other.y;
        return du < other.du;
    }
};
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    k -= n - 1 + m - 1;
    if (k < 0 || k % 2)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < m; ++j)
            cout << (i == n - 1 && j == 2 ? 'B' : (j % 2 ? 'B' : 'R')) << (j == m - 1 ? '\n' : ' ');
    for (int i = 1; i < n; ++i)
        for (int j = 1; j <= m; ++j)
            cout << ((n - i) % 2 ? 'R' : 'B') << (j == m ? '\n' : ' ');
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