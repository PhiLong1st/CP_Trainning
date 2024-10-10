
/*
    Code by: KoKoDuDu
    Created: 29.09.2024 15:54:44
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> d(n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        d[x]++;
        d[y]++;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (d[i] == 1);
    }
    if (p % ans == 1) {
        cout << 2 * (p / ans) + 1;
    }
    else {
        cout << 2 * ((p + ans - 1) / ans);
    }
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