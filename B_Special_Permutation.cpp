
/*
    Code by: KoKoDuDu
    Created: 28.09.2024 14:45:17
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (n == 2) {
        cout << a << ' ' << b << '\n';
        return;
    }
    vector<int> ans(n + 1);
    if (a > b) {
        if (a != n / 2 + 1 || b != n / 2) {
            cout << -1 << "\n";
            return;
        }
        for (int i = n; i >= 1; --i) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    if (min(a, b) >= n / 2 + 1 || max(a, b) <= n / 2) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 1; i <= n; ++i) {
        ans[i] = i;
    }
    swap(ans[a], ans[b]);
    reverse(ans.begin() + 1, ans.end());
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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