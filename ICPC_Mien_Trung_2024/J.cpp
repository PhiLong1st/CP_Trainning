

/*
    Code by: KoKoDuDu
    Created: 22.10.2024 15:42:07
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
struct LCA {
    int n;
    vector<vector<int>>adj, cha;
    vector<int> d;
    LCA(int n, vector<vector<int>> a) {
        adj = a;
        this->n = n;
        d.assign(n + 1, 0);
        cha.assign(n + 1, vector<int>(21));
        prepare();
    }
    void dfs(int x, int par) {
        for (int i = 0; i < adj[x].size(); i++) {
            int g = adj[x][i];
            if (g != par)
            {
                d[g] = d[x] + 1;
                cha[g][0] = x;
                dfs(g, x);
            }
        }
    }
    void prepare() {
        dfs(1, 0);
        for (int j = 1; j <= 20; j++) {
            for (int i = 1; i <= n; i++) {
                cha[i][j] = cha[cha[i][j - 1]][j - 1];
            }
        }
        d[0] = -1;
    }
    int lca(int u, int v) {
        if (d[u] < d[v]) {
            return lca(v, u);
        }
        for (int j = 20; j >= 0; j--) {
            if (d[cha[u][j]] >= d[v]) {
                u = cha[u][j];
            }
        }
        if (u == v) {
            return u;
        }
        for (int j = 20; j >= 0; j--) {
            if (cha[u][j] != cha[v][j]) {
                u = cha[u][j];
                v = cha[v][j];
            }
        }
        return cha[u][0];
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>>adj(n + 1, vector<int>());
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    LCA tree(n, adj);
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        int xz = tree.lca(x, z);
        int yx = tree.lca(x, y);
        int yz = tree.lca(y, z);
        if ((y == yz && yx == xz) || (y == yx && yz == xz)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
        // cout << tree.lca(x, z) << tree.lca(x, y) << ' ' << tree.lca(z, y) << '\n';
        // cout << 'a';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}