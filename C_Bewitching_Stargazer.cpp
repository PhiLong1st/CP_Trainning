/*
    Code by: KoKoDuDu
    Created: 28.12.2024 21:59:52
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    int sum = 0, cur = 1;
    int tmp = n;
    while (n >= k) {
        if (n % 2 != 0) {
            sum += cur;
        }
        n /= 2;
        cur *= 2;
    }
    cout << (tmp + 1) * sum / 2 << '\n';
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