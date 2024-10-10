
/*
    Code by: KoKoDuDu
    Created: 01.10.2024 15:29:39
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, sum = 0;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    int val = 2 * sum / n;
    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (val - a[i] >= 0) {
            ans += mp[val - a[i]];
        }
        mp[a[i]]++;
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