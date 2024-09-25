/*
    Code by: KoKoDuDu
    Created: 21.09.2024 03:20:26
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    a[0] = 1;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int l = 0, r = n - 1;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] >= b[r]) {
            ans++;
            l++;
        }
        else {
            r--;
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