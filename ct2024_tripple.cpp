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
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    if (n <= 1000)
    {
        vector2d(ke, n + 1, n + 1, int, 0);
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            x++;
            y++;
            ke[x][y] = 1;
            ke[y][x] = 1;
        }
        int ans = 0;
        for (int i = 1; i <= n - 2; i++)
        {
            for (int j = i + 1; j <= n - 1; j++)
            {
                for (int k = j + 1; k <= n; k++)
                {
                    bool ok = (ke[i][j] | ke[i][k] | ke[j][k]);
                    if (!ok)
                    {
                        ans += a * arr[i] + b * arr[j] + c * arr[k];
                    }
                }
            }
        }
        cout << ans;
        return;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        x++;
        y++;
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