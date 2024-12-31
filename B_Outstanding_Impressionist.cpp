
/*
    Code by: KoKoDuDu
    Created: 28.12.2024 21:43:46
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), save(2 * n + 1), cnt(2 * n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        if (a[i] == b[i]) {
            save[a[i]] = 1;
            cnt[a[i]]++;
        }
    }
    for (int i = 1; i <= 2 * n; ++i) {
        save[i] += save[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        int val = save[b[i]] - save[a[i] - 1];
        // cout << val << ' ';
        if (a[i] == b[i]) {
            cout << (cnt[a[i]] == 1);
            continue;
        }
        if (val == b[i] - a[i] + 1) {
            cout << 0;
        }
        else {
            cout << 1;
        }
    }
    cout << '\n';
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