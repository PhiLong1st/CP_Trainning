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
    int n, q;
    cin >> n >> q;
    vector<int> par(n + 1), st(n + 1), per(n + 1), pos(n + 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> par[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> per[i];
    }
    int dem = 0;
    function<void(int id)> dfs = [&](int id)
    {
        if (id > n)
        {
            return;
        }
        dem++;
        st[id] = per[dem];
        pos[per[dem]] = id;
        dfs(id * 2);
        dfs(id * 2 + 1);
    };
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << pos[i] << " ";
    }
    cout << "\n";
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        // swap(st[pos[x]], st[pos[y]]);
        swap(pos[per[x]], pos[per[y]]);
        swap(per[x], per[y]);
        for (int i = 1; i <= n; i++)
        {
            cout << pos[i] << " ";
        }
        cout << "\n";
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