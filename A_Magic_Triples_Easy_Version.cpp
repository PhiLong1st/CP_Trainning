/*
    Code by: KoKoDuDu
    Created: 11.10.2024 15:33:24
*/
#include <bits/stdc++.h>
#define int long long 
using namespace std;

// #define int long long
#define pll pair<int, int>
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map <int, int> cnt, vst;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int ans = 0;
    for (int u = 1; u <= n; ++u) {
        int i = a[u];
        if (vst[i]) continue;
        vst[i] = 1;
        ans += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2);
        for (int j = 2; j * j <= i; ++j) {
            if (i % (j * j) == 0) {
                ans += cnt[i / j] * cnt[i] * cnt[i / (j * j)];
            }
        }
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