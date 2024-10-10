
/*
    Code by: KoKoDuDu
    Created: 26.09.2024 02:10:05
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ans = n;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ans = max({ ans, 2 * (i + 1),2 * (n - i) });
        }
    }
    cout << ans << "\n";
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