/*
    Code by: KoKoDuDu
    Created: 27.12.2024 17:31:52
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, s, t;
    cin >> n >> s >> t;
    vector<vector<int>>adj(n + 1, vector<int>());
    vector<int> vst(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int node = -1;
    auto dfs1 = [&](auto&& dfs1, int p, int u) -> bool {
        vst[u] = true;
        for (auto v : adj[u]) {
            if (v != p && vst[v]) {
                node = v;
                return true;
            }
            else if (v != p && !vst[v]) {
                if (dfs1(dfs1, u, v)) {
                    return true;
                }
            }
        }
        return false;
        };
    auto dfs2 = [&](auto&& dfs2, int u) -> int {
        vst[u] = true;
        int dist = n;
        for (auto v : adj[u]) {
            if (v == node) {
                return 1;
            }
            if (!vst[v]) {
                int tmp = dfs2(dfs2, v) + 1;
                dist = min(tmp, dist);
            }
        }
        return dist;
        };

    dfs1(dfs1, -1, t);
    vst.assign(n + 1, false);
    int distMarcel = (node == s) ? 0 : dfs2(dfs2, s);
    vst.assign(n + 1, false);
    int distValeriu = (node == t) ? 0 : dfs2(dfs2, t);
    cout << ((distValeriu < distMarcel) ? "YES\n" : "NO\n");
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