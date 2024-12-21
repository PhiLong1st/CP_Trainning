
/*
    Code by: KoKoDuDu
    Created: 19.12.2024 18:55:59
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    int n, m;  cin >> n >> m;
    vector<array<int, 2>> adj[n];
    for (int e = 0; e < m; ++e) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, -w });
    }

    map<int, int> pos;
    for (int u = 0; u < n; ++u) {
        if (!pos.count(u)) {
            queue<int> q;  
            q.push(u);
            pos[u] = 0;
            while (!q.empty()) {
                auto u = q.front();  
                q.pop();
                for (auto x : adj[u]) {
                    int v = x[0];
                    int w = x[1];
                    if (pos.count(v)) {
                        if (pos[v] - pos[u] != w) {
                            cout << "NO\n";
                            return;
                        }
                    }
                    else {
                        pos[v] = pos[u] + w;
                        q.push(v);
                    }
                }
            }
        }
    }

    cout << "YES\n";
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