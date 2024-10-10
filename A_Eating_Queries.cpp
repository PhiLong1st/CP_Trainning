
/*
    Code by: KoKoDuDu
    Created: 02.10.2024 17:11:27
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end(), greater<>());
    for (int i = 1; i <= n; ++i) {
        a[i] += a[i - 1];
        // cerr << a[i] << " ";
    }
    // cerr << "\n";
    while (q--) {
        int x;
        cin >> x;
        if (x > a[n]) {
            cout << -1 << '\n';
            continue;
        }
        cout << lower_bound(a.begin() + 1, a.end(), x) - a.begin() << "\n";
    }
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