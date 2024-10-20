

/*
    Code by: KoKoDuDu
    Created: 20.10.2024 12:36:57
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> a(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        int val = m / a[i];//luong rot 1 chu ki
        int num = t / m;// so lan chu ki
        int du = t % m;
        ans += val * num + du / a[i];
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