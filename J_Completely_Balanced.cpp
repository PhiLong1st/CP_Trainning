

/*
    Code by: KoKoDuDu
    Created: 26.10.2024 18:25:09
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
const int INF = 1e18;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin() + 1, a.end());
    if (n == 1) {
        cout << sum << '\n';
        return;
    }
    if (n % 2 == 0) {
        int best = INF;
        int val1 = a[(n + 1) / 2], val2 = a[(n + 1) / 2 + 1];
        if (val1 * (n + 1) - sum <= val1) {
            best = min(best, val1 * (n + 1) - sum);
        }
        if (sum % n == 0 && (sum / n) >= val1 && (sum / n) <= val2) {
            best = min(best, sum / n);
        }
        if (val2 * (n + 1) - sum >= val2) {
            best = min(best, val2 * (n + 1) - sum);
        }
        cout << best << '\n';
    }
    else {
        int best = INF;
        int val1 = a[(n + 1) / 2], val2 = a[(n + 1) / 2 - 1];
        if (val1 * (n + 1) - sum >= val1) {
            best = min(best, val1 * (n + 1) - sum);
        }
        if (sum % n == 0 && (sum / n) <= val1 && (sum / n) >= val2) {
            best = min(best, sum / n);
        }
        if (val2 * (n + 1) - sum <= val2) {
            best = min(best, val2 * (n + 1) - sum);
        }
        cout << best << '\n';
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