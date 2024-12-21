
/*
    Code by: KoKoDuDu
    Created: 20.12.2024 18:23:45
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1), cnt;
    vector<pll> save;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        save.push_back({ a[i], 1 });
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        save.push_back({ b[i], 2 });
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    auto cmp = [&](pll a, pll b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
        };
    sort(save.begin(), save.end(), cmp);
    stack<int> st;
    for (int i = n * 2 - 1; i >= 0; --i) {
        if (save[i].second == 2) {
            st.push(save[i].first);
        }
        else {
            cnt.push_back(st.top() - save[i].first);
            st.pop();
        }
    }
    sort(cnt.begin(), cnt.end(), greater<>());
    sort(c.begin(), c.end());
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += c[i] * cnt[i - 1];
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