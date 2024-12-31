
/*
    Code by: KoKoDuDu
    Created: 29.12.2024 15:19:15
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (n % 2 != 0) {
        cout << "YES\n";
    }
    else {
        for (int i = 1; i <= n - 2; i += 2) {
            if (a[i] <= a[i + 1]) {
                a[i + 2] -= abs(a[i] - a[i + 1]);
            }
            else {
                a[i + 2] += abs(a[i] - a[i + 1]);
            }
        }
        cout << ((a[n - 1] <= a[n]) ? "YES\n" : "NO\n");
    }
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