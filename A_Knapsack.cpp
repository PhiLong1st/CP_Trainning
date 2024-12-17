
/*
    Code by: KoKoDuDu
    Created: 14.12.2024 22:16:41
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, w;
    cin >> n >> w;
    vector<pll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin() + 1, a.end(), greater<>());
    vector<int> ans;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (sum + a[i].first <= w) {
            sum += a[i].first;
            ans.push_back(a[i].second);
        }
    }
    if (ans.empty() || sum * 2 < w) {
        cout << -1 << '\n';
        return;
    }
    cout << ans.size() << '\n';
    for (int i : ans) {
        cout << i << ' ';
    }
    cout << "\n";
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