

/*
    Code by: KoKoDuDu
    Created: 25.10.2024 20:31:48
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
int dp[20][11][2];
vector<int>num;
int call(int pos, int sum, int state) {
    if (sum > 10) return 0;
    if (pos == (int)num.size()) return (sum == 10);
    if (dp[pos][sum][state] != -1) return dp[pos][sum][state];
    int res = 0, lmt = 9;
    if (!state) lmt = num[pos];
    for (int digit = 0; digit <= lmt; ++digit) {
        int new_state = state, new_cnt = sum;
        new_cnt += digit;
        if (!state && digit < lmt) new_state = 1;
        if (new_cnt <= 10) res += call(pos + 1, new_cnt, new_state);
    }
    return dp[pos][sum][state] = res;
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
    int res = call(0, 0, 0);
    return res;
}
void solve() {
    int n;
    cin >> n;

    int l = 1, r = 1e16, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (calc(mid) < n) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
            ans = mid;
        }
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