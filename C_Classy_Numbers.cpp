

/*
    Code by: KoKoDuDu
    Created: 24.10.2024 16:20:15
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

int dp[19][4][2];
vector<int>num;
int call(int pos, int cnt, int state) {
    if (cnt > 3) return 0;
    if (pos == (int)num.size()) return (cnt <= 3);
    if (dp[pos][cnt][state] != -1) return dp[pos][cnt][state];
    int res = 0, lmt = 9;
    if (!state) lmt = num[pos];
    for (int digit = 0; digit <= lmt; ++digit) {
        int new_state = state, new_cnt = cnt;
        if (digit != 0) new_cnt += 1;
        if (!state && digit < lmt) new_state = 1;
        if (new_cnt <= 3) res += call(pos + 1, new_cnt, new_state);
    }
    return dp[pos][cnt][state] = res;
}
int calc(int b) {
    num.clear();
    while (b > 0) {
        num.push_back(b % 10);
        b /= 10;
    }
    reverse(num.begin(), num.end());
    memset(dp, -1, sizeof(dp));
    int ok = 0, cnt = 0;
    if (num.size() != 0) {
    }
    int res = call(0, 0, 0);
    return res;
}
void solve() {
    int l, r;
    cin >> l >> r;
    // cout << calc(r) << ' ' << calc(l - 1) << '\n';
    cout << calc(r) - calc(l - 1) << '\n';
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