
/*
    Code by: KoKoDuDu
    Created: 18.12.2024 12:46:47
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1, vector<int>());
    vector<vector<int>> height(n + 1, vector<int>());
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    function<void(int, int, int)> dfs = [&](int x, int par, int h) {
        height[h].push_back(x);
        for (int g : adj[x]) {
            if (g != par) {
                dfs(g, x, h + 1);
            }
        }
        };
    dfs(1, 0, 1);
    for (int i = 1; i <= n; i++) {
        cout << i << "- ";
        for (int x : height[i]) {
            cout << x << ' ';
        }
        cout << "\n---\n";
    }
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