

/*
    Code by: KoKoDuDu
    Created: 24.10.2024 16:20:15
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
int  k;
int dp[101][4][2];
vector<int>num;
int call(int pos, int cnt, int state) {
    if (cnt > k) return 0;
    if (pos == (int)num.size()) return (cnt == k);
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
int calc(string b) {
    num.clear();
    for (auto x : b) {
        num.push_back(x - '0');
    }
    memset(dp, -1, sizeof(dp));
    int res = call(0, 0, 0);
    return res;
}
void solve() {
    string n;
    cin >> n >> k;
    cout << calc(n) << '\n';
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