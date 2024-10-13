/*
    Code by: KoKoDuDu
    Created: 10.10.2024 16:13:00
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
    vector<pll> range(n + 1), save(n + 1);
    for (int i = 2; i <= n; ++i) {
        int par;
        cin >> par;
        adj[i].push_back(par);
        adj[par].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> range[i].first >> range[i].second;
    }
    int ans = 0;
    function<void(int, int)> dfs;
    dfs = [&](int par, int x) {
        if (save[par].first > range[x].second || save[par].second < range[x].first) {
            ans++;
            save[x] = range[x];
        }
        else {
            save[x].first = max(save[x].first, save[par].first);
            save[x].second = min(save[x].second, save[par].second);
        }
        for (int g : adj[x]) {
            if (g == par) continue;
            dfs(x, g);
        }
        };
    save[0] = range[1];
    dfs(0, 1);
    cout << ans << '\n';
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