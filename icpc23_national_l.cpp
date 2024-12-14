
/*
    Code by: KoKoDuDu
    Created: 29.11.2024 18:15:39
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m + 1), rank(n + 2);
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    for (int l = 1; l <= m; ++l) {
        vector<int> cnt(n + 2), cntBigger(m + 2);
        for (int r = l; r <= min(m, l + k - 1); ++r) {
            rank[a[r]] = max(rank[a[r]], cntBigger[cnt[a[r]] + 1]);
            cnt[a[r]]++;
            cntBigger[cnt[a[r]]]++;
            rank[a[r]] = max(rank[a[r]], cntBigger[cnt[a[r]] + 1]);
        }
        for (int i = 1; i <= n; ++i) {
            rank[i] = max(rank[i], cntBigger[cnt[i] + 1]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << rank[i] + 1 << ' ';
    }
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