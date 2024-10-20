

/*
    Code by: KoKoDuDu
    Created: 19.10.2024 09:44:32
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<pll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].second;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
    }
    int ans = 0;
    sort(a.begin() + 1, a.end(), greater<>());
    vector<int>save(n + 1, n), cnt(n + 1, n);
    for (int i = 1; i <= n; ++i) {
        cout << a[i].first << ' ';
        if (a[i].second > n) {
            ans += a[i].first;
            continue;
        }
        int minn = INT_MAX;
        for (int j = a[i].second; j <= n; ++j) {
            minn = min(minn, save[j]);
        }
        if (minn == 0) {
            continue;
        }
        ans += a[i].first;
        for (int j = a[i].second; j <= n; ++j) {
            minn = min(minn, save[j]);
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