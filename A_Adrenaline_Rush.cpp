
/*
    Code by: KoKoDuDu
    Created: 17.12.2024 15:39:36
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), pos(n + 1), used(n + 1);
    iota(pos.begin(), pos.end(), 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    reverse(a.begin() + 1, a.end());
    vector<pll> ans;
    vector<int> pre, suf;
    for (int i = 1; i <= n; ++i) {
        pre.push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = (int)pre.size() - 1; j >= 0; --j) {
            if (used[j]) continue;
            if (pre[j] == a[i]) {
                used[j] = 1;
                continue;
            }
            if (pre[j] < a[i]) {
                ans.push_back({ a[i],pre[j] });
                // cout << a[i] << ' ' << pre[j] << '\n';
            }
        }
        // cout << "----\n";
        for (int j = 0; j < (int)suf.size(); ++j) {
            ans.push_back({ a[i],suf[j] });
            // cout << a[i] << ' ' << suf[j] << '\n';
        }
        // cout << "++++\n";
        suf.push_back(a[i]);
    }
    cout << (int)ans.size() << '\n';
    for (auto x : ans) {
        cout << x.first << ' ' << x.second << '\n';
    }
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