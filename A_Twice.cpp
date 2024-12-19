
/*
    Code by: KoKoDuDu
    Created: 19.12.2024 15:23:41
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= n; ++i) {
        ans += cnt[i] / 2;
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