
/*
    Code by: KoKoDuDu
    Created: 20.12.2024 21:51:19
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += s[i] == 'p';
        if (s[i] == 's') {
            if (cnt != 0) {
                cout << "NO\n";
                return;
            }
        }
    }
    int dem_1 = 0, dem_2 = 0;
    for (int i = 2; i < n; ++i) {
        dem_1 += s[i] == 's';
        dem_2 += s[i] == 'p';
    }
    if (min(dem_1, dem_2) > 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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