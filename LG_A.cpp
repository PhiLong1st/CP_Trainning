

/*
    Code by: KoKoDuDu
    Created: 12.10.2024 08:26:57
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> pos, neg;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (x < 0) {
            neg.push_back(-x);
        }
        else {
            pos.push_back(x);
        }
    }
    if (!neg.empty())
        sort(neg.begin(), neg.end());
    if (!pos.empty())
        sort(pos.begin(), pos.end());
    int ans = 0;
    for (int i = (int)neg.size() - 1; i >= 0; i -= k) {
        ans += 2 * neg[i];
    }
    for (int i = (int)pos.size() - 1; i >= 0; i -= k) {
        ans += 2 * pos[i];
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}