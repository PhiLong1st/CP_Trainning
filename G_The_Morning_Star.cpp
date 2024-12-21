
/*
    Code by: KoKoDuDu
    Created: 19.12.2024 18:36:49
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    map<int, int> ver, hor, diag_1, diag_2;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        ver[x]++, hor[y]++, diag_1[x - y]++, diag_2[x + y]++;
    }
    int ans = 0;
    for (auto x : ver) {
        ans += x.second * (x.second - 1);
    }
    for (auto x : hor) {
        ans += x.second * (x.second - 1);
    }
    for (auto x : diag_1) {
        ans += x.second * (x.second - 1);
    }
    for (auto x : diag_2) {
        ans += x.second * (x.second - 1);
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