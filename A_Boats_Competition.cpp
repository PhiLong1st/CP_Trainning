

/*
    Code by: KoKoDuDu
    Created: 13.10.2024 17:22:47
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << "0\n";
        return;
    }
    int ans = 0;
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= 100; ++i) {
        int tmp_ans = 0;
        map<int, int> cnt;
        for (int j = 1; j <= n; ++j) {
            if (i >= a[j] && cnt[i - a[j]] != 0) {
                tmp_ans++;
                cnt[i - a[j]]--;
            }
            else {
                cnt[a[j]]++;
            }
        }
        ans = max(ans, tmp_ans);
    }
    cout << ans << "\n";
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