
/*
    Code by: KoKoDuDu
    Created: 29.11.2024 19:55:52
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1), ans(n + 1);
    vector<pll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
        a[i].first = x;
        a[i].second = i;
        // ans[i] = x;
    }
    sort(a.begin() + 1, a.end());
    int max_preq = *max_element(cnt.begin(), cnt.end());
    for (int i = 1; i <= n - max_preq; ++i) {
        ans[a[i + max_preq].second] = a[i].first;
    }
    for (int i = n - max_preq + 1; i <= n; ++i) {
        ans[a[i + max_preq - n].second] = a[i].first;
    }
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