
/*
    Code by: KoKoDuDu
    Created: 17.12.2024 10:37:35
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, s, m;
    cin >> n >> s >> m;
    bool isOk = false;
    int pos = 0;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        isOk |= (x - pos >= s);
        pos = y;
    }
    isOk |= (m - pos >= s);
    if (isOk) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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