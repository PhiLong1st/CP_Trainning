/*
    Code by: linvg
    Created: 21.09.2024 22:36:00
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int>a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        b[i] = min(b[i], k * m);
    }
    int ans = 0, l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        if (r < a[i]) {
            l = a[i];
            r = a[i] + b[i] / m;
            ans += b[i] / m;
        }
        else {
            l = r + 1;
        }
        ans += min(a[i] + k - l, b[i] / m);
    }
    cout << ans << "\n";//+min(b[n] / m, r - l + 1);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    cin >> numTest;
    while (numTest--) {
        solve();
    }
    return 0;
}