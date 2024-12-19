
/*
    Code by: KoKoDuDu
    Created: 18.12.2024 11:17:55
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        bool isOk = true;
        for (int j = 1; j <= n; ++j) {
            if (i == j)continue;
            if (abs(a[i] - a[j]) % k == 0) {
                isOk = false;
            }
        }
        if (isOk) {
            cout << "YES\n";
            cout << i << '\n';
            return;
        }
    }
    cout << "NO\n";
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