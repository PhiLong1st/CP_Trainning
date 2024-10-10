
/*
    Code by: KoKoDuDu
    Created: 27.09.2024 15:19:12
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
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            cnt++;
        }
        else {
            if (cnt > 1) {
                ans += cnt;
            }
            cnt = 0;
        }
    }
    if (cnt > 1) {
        ans += cnt;
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    while (numTest--) {
        solve();
    }
    return 0;
}