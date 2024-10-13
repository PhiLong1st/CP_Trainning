/*
    Code by: KoKoDuDu
    Created: 13.10.2024 08:12:13
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
const int INF = 1e18;
int sum = 0, minn = INF, cnt = 0;
void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1), a(n + 1), b(n + 1), pos(n + 1), check(n + 1), color(n + 1), par(n + 1);
    vector<vector<pll>>adj(n + 1, vector<pll>());
    int color_min = INF;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
        color_min = min(color_min, w[i]);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        par[pos[b[i]]] = i;
    }
    function< void(int)> dfs = [&](int x) {
        if (check[x]) return;
        // cout << x << " ";
        // cout << x << " " << w[a[x]] << "\n";
        cnt++;
        check[x] = 1;
        sum += w[a[x]];
        minn = min(minn, w[a[x]]);
        dfs(par[x]);
        };
    int ans = 0;
    vector<array<int, 3>>best;
    for (int i = 1; i <= n; i++) {
        // cout << i << " " << par[i] << "\n";
        if (check[i] == 1) continue;
        sum = 0, minn = INF, cnt = 0;
        dfs(i);
        // ans += max(0LL, sum + minn * (cnt - 2));
        best.push_back({ sum, minn ,cnt });
    }
    int save = INF;
    for (auto state : best) {
        int sum = state[0], minn = state[1], cnt = state[2];
        if (color_min == minn) {
            ans += max(0LL, sum + minn * (cnt - 2));
        }
        else {
            int bonus = 2 * (color_min + minn);
            int val_1 = max(0LL, sum + minn * (cnt - 2));
            int val_2 = max(0LL, sum + color_min * (cnt - 2));
            ans += min(val_1, val_2 + bonus);
        }
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