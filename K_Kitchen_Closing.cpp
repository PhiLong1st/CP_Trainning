

/*
    Code by: KoKoDuDu
    Created: 11.10.2024 22:41:06
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1);
    vector<vector<pll>> b(m + 1, vector<pll>());
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        int t;
        cin >> t;
        while (t--)
        {
            int x, y;
            cin >> x >> y;
            b[i].push_back({ x, y });
        }
    }
    int ans = 0;
    for (int i = 1; i <= k; ++i) {
        int t;
        cin >> t;
        vector <int> cnt(m + 1);
        for (int j = 1; j <= t; ++j) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        for (int j = 1; j <= m; ++j) {
            if (cnt[j] == 0) continue;
            for (auto u : b[j]) {
                if (a[u.first] < u.second * cnt[j]) {
                    cout << ans;
                    return;
                }
                a[u.first] -= u.second * cnt[j];
            }
        }
        // cerr << "\n";
        ans++;
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