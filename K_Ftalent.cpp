

/*
    Code by: KoKoDuDu
    Created: 20.10.2024 08:14:54
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int ans = INT_MAX;
    int minn = *min_element(a.begin() + 1, a.end());
    int maxx = *max_element(a.begin() + 1, a.end());

    cout << maxx - minn << '\n';
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