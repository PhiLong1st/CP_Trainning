
/*
    Code by: KoKoDuDu
    Created: 20.12.2024 21:36:51
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
    int cnt = 0, l = -1, r = -1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] != 0) {
            r = i;
        }
    }
    for (int i = n; i >= 1; --i) {
        if (a[i] != 0) {
            l = i;
        }
    }
    if (l == -1) {
        cout << 0 << '\n';
        return;
    }
    bool isOk = false;
    for (int i = l; i <= r; ++i) {
        if (a[i] == 0) {
            isOk = true;
        }
    }
    if (!isOk) {
        cout << 1 << '\n';
        return;
    }
    cout << 2 << '\n';
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