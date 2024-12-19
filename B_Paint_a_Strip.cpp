
/*
    Code by: KoKoDuDu
    Created: 18.12.2024 11:27:27
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 <<'\n';
        return ;
    }
    int ans = 2;
    int val = 4;
    while (val < n) {
        val = (val + 1) * 2;
        ans++;
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