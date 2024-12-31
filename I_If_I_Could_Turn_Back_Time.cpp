
/*
    Code by: KoKoDuDu
    Created: 30.12.2024 20:06:32
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
    for (int i = 1; i <= n; ++i) {
        if (a[i].first < a[i].second) {
            cout << -1 << '\n';
            return;
        }
    }
    if (n == 1) {
        cout << a[1].first - a[1].second << '\n';
        return;
    }
    int used = 0;
    sort(a.begin() + 1, a.end());
    for (int i = 1; i < n; ++i) {
        if (a[i].first == a[i + 1].first && a[i].second != a[i + 1].second) {
            cout << -1 << '\n';
            return;
        }
        if (a[i].second > a[i + 1].second) {
            cout << -1 << '\n';
            return;
        }
    }
    int maxx = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i].first - used < a[i].second) {
            cout << -1 << '\n';
            return;
        }

        used += a[i].first - used - a[i].second;
        maxx = max(maxx, a[i].second);
        // cout << used << ' ';
    }
    cout << used << '\n';
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