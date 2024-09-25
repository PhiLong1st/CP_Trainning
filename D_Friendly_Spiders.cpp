
/*
    Code by: KoKoDuDu
    Created: 25.09.2024 18:53:39
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, s, t;
    cin >> n;
    vector<int> a(n + 1);
    map<array<int, 2>, vector<array<int, 2>>>adj;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cin >> s >> t;
    for (int i = 1; i <= n; ++i) {
        int val = a[i];
        for (int j = 2; j * j <= a[i]; ++j) {
            if (val % j == 0) {
                adj[{1LL, a[i]}].push_back({ 2LL, j });
                adj[{2LL, j}].push_back({ 1LL, a[i] });
            }
        }
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