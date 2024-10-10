/*
    Code by: KoKoDuDu
    Created: 04.10.2024 23:44:18
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int ans = 0, l = 1, cnt = 0, pos = 0;
    a[n + 1] = a[n] - 1;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, i - l + 1);
        if (a[i] >= a[i + 1]) {
            if (cnt == 0) {
                cnt++;
                pos = i;
                ans = max(ans, i - l + 1);
            }
            else {
                cnt = 0;
                l = pos + 1;
            }
        }
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