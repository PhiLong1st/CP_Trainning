
/*
    Code by: KoKoDuDu
    Created: 02.10.2024 18:04:47
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a, b;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        ans += (n - 1) * min(x, y);
        if (x > y) {
            a.push_back(x - y);
        }
        else {
            b.push_back(y - x);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < a.size(); i++) {
        ans += a[i] * (a.size() - 1 - i);
    }
    for (int i = 0; i < b.size(); i++) {
        ans += b[i] * (b.size() - 1 - i);
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