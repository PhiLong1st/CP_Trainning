
/*
    Code by: KoKoDuDu
    Created: 08.12.2024 17:42:39
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) cin >> p[i];
    vector<vector<int>> adj(n + 1), par(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        par[v].push_back(u);
    }
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; ++i) {
        vector<int> deg(n + 1);
        for (int j = 1; j <= n; ++j) {
            for (int k : par[j]) {
                deg[k]++;
            }
        }
        priority_queue<pair<int, int>> q;
        for (int j = 1; j <= n; ++j) {
            if (deg[j] == 0 && j != i) {
                q.push({ p[j], j });
            }
        }

        for (int j = n; j >= 1; --j) {
            if (q.empty() || q.top().first < j) {
                if (deg[i] == 0 && j <= p[i]) {
                    ans[i] = j;
                }
                break;
            }
            int u = q.top().second;
            q.pop();
            for (int v : par[u]) {
                if (--deg[v] == 0 && v != i) {
                    q.push({ p[v], v });
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
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