

/*
    Code by: KoKoDuDu
    Created: 25.10.2024 22:38:52
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), dist(n + 1), num_child(n + 1);
    vector<vector<pll>> adj(n + 1, vector<pll>());
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        int v, w;
        cin >> v >> w;
        adj[i + 1].push_back({ v,w });
        adj[v].push_back({ i + 1,w });
    }
    int ans = 0;
    function<void(int, int)> dfs1 = [&](int par, int x) {
        for (auto e : adj[x]) {
            int g = e.first;
            int w = e.second;
            if (g != par) {
                dist[g] = dist[x] + w;
                dfs1(x, g);
                num_child[x] += num_child[g] + 1;
            }
        }
        };
    dfs1(0, 1);
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << dist[i] << ' ' << num_child[i] << '\n';
    // }
    function<void(int, int, int)> dfs2 = [&](int par, int x, int minn) {
        // cout << x << ' ' << minn << '\n';
        for (auto e : adj[x]) {
            int g = e.first;
            int w = e.second;
            if (g != par) {
                if (dist[g] - a[g] > minn) {
                    ans += num_child[g] + 1;
                    // cout << g << ' ';
                    continue;
                }
                dfs2(x, g, min(minn, dist[g]));
            }
        }
        };
    dfs2(0, 1, dist[1]);
    cout << ans;
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