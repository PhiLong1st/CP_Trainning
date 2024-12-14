
/*
    Code by: KoKoDuDu
    Created: 06.12.2024 16:48:53
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> deg(n + 1);
    vector<vector<int>>adj(n + 1, vector<int>());
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        deg[i] = adj[i].size();
    }
    int ans = -n;
    auto dfs = [&](auto&& self, int x, int par) -> int {
        int best_1 = 0, best_2 = 0;
        for (int g : adj[x]) {
            if (g == par) continue;
            int val = self(self, g, x);
            if (val > best_1) {
                best_2 = best_1;
                best_1 = val;
            }
            else {
                best_2 = max(best_2, val);
            }
        }
        ans = max(ans, best_1 + best_2 + deg[x] - 2);
        return best_1 + deg[x] - 2;
        };
    dfs(dfs, 1, 0);
    cout << ans + 2 << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}