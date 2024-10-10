
/*
    Code by: KoKoDuDu
    Created: 26.09.2024 03:34:07
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> c(3, vector<int>(n + 1)), adj(n + 1, vector<int>());
    vector<int>res(n + 1);
    for (int i = 0; i <= 2; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() >= 3) {
            cout << -1 << "\n";
            return;
        }
    }
    function< int(int, int, int, int, bool)>dfs;
    dfs = [&](int par, int x, int fi, int se, bool type) {
        if (type) {
            res[x] = fi + 1;
        }
        for (int g : adj[x]) {
            if (g == par) continue;
            return c[fi][x] + dfs(x, g, (fi + se) % 3, se, type);
        }
        return c[fi][x];
        };
    int pos = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            pos = i;
        }
    }
    vector<int>ans(6);
    int best = 0;
    for (int i = 0; i < 6;i++) {
        ans[i] = dfs(0LL, pos, i % 3, i / 3 + 1, false);
        if (ans[i] < ans[best]) best = i;
    }
    cout << ans[best] << "\n";
    dfs(0, pos, best % 3, best / 3 + 1, true);
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    while (numTest--) {
        solve();
    }
    return 0;
}