
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
    vector<int> ans(n + 1);
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
    int pre = 2, suf = 2 * n;
    for (int i = 1; i <= n; i++) {
        // cout << i << "- ";
        if (i % 2 == 0) {
            for (int x : height[i]) {
                // cout << x << ' ';
                ans[x] = pre;
                pre += 2;
            }
        }
        else {
            for (int x : height[i]) {
                // cout << x << ' ';
                ans[x] = suf;
                suf -= 2;
            }
        }
        // cout << "\n---\n";
    }
    function<void(int, int, int)> check = [&](int x, int par, int h) {
        for (int g : adj[x]) {
            if (g != par) {
                if (abs(ans[g] - ans[x]) == 2) {
                    ans[g] = ans[x] - 1;
                }
                check(g, x, h + 1);
            }
        }
        };
    check(1, 0, 1);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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