/*
    Code by: KoKoDuDu
    Created: 10.10.2024 11:00:18
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), valChild(n + 1), sumChild(n + 1), sumPar(n + 1);
    vector<vector<int>>adj(n + 1, vector<int>());
    int sumAll = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sumAll += a[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    function< void(int, int) > dfs;
    dfs = [&](int par, int x) {
        for (int g : adj[x]) {
            if (g == par) continue;
            dfs(x, g);
            sumChild[x] += sumChild[g];
            valChild[x] += valChild[g] + sumChild[g];
        }
        sumChild[x] += a[x];
        // cout << par << ' ' << x << ' ' << valChild[x] << ' ' << sumChild[x] << '\n';
        };
    dfs(0, 1);
    function< void(int, int) > dfs2;
    dfs2 = [&](int par, int x) {
        for (int g : adj[x]) {
            if (g == par) continue;
            sumPar[g] = sumPar[x] + (sumAll - sumChild[g]) + (valChild[x] - valChild[g] - sumChild[g]);
            dfs2(x, g);
            // cout << g << ' ' << x << ' ' << sumPar[g] << ' ' << (valChild[x] - valChild[g] - sumChild[g]) << '\n';
        }
        };
    dfs2(0, 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        // cerr << valChild[i] << ' ';
        ans = max(ans, valChild[i] + sumPar[i]);
    }
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