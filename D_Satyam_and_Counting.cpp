
/*
    Code by: KoKoDuDu
    Created: 16.12.2024 16:31:09
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt_x, cnt_y;
    vector<int> save_0, save_1;
    for (int i = 1; i <= n; ++i) {
        int u, v;
        cin >> u >> v;
        if (v == 0) {
            save_0.push_back(u);
            cnt_x[u]++;
        }
        else {
            save_1.push_back(u);
            cnt_y[u]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < save_0.size(); ++i) {
        int val = save_0[i];
        ans += cnt_y[val] * ((int)save_1.size() - 1);
        ans += cnt_y[val - 1] * cnt_y[val + 1];
    }
    for (int i = 0; i < save_1.size(); ++i) {
        int val = save_1[i];
        ans += cnt_x[val] * ((int)save_0.size() - 1);
        ans += cnt_x[val - 1] * cnt_x[val + 1];
    }
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