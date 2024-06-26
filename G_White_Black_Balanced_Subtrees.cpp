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
    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    string s;
    cin >> s;
    s = " " + s;
    int ans = 0, numW = 0, numB = 0;
    function<void(int x, int par)> dfs = [&](int x, int par)
    {
        int u = numW, v = numB;
        numW += (s[x] == 'W');
        numB += (s[x] == 'B');
        for (int g : adj[x])
        {
            if (g != par)
            {
                dfs(g, x);
            }
        }
        ans += (numW - u == numB - v);
        // if (numW - u == numB - v)
        // {
        //     cout << x << " " << u << " " << v << "\n";
        // }
    };
    dfs(1, 0);
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