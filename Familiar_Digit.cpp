
/*
    Code by: KoKoDuDu
    Created: 03.12.2024 16:20:35
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

int cal(string num, int mask) {
    vector<vector<vector<int>>> dp(2002, vector<vector<int>>(2, vector<int>(1025, -1)));
    function<int(int, int, int)> call = [&](int pos, int status, int state) {
        if (pos == (int)num.size()) {
            return (int)(state == mask);
        }
        if (dp[pos][status][state] != -1) {
            return dp[pos][status][state];
        }
        int ans = 0;
        char LMT = '9';
        if (status == 0) {
            LMT = num[pos];
        }
        char st = '0';
        // for (char dgt = '0'; dgt <= LMT; dgt++) {
        //     int new_status = status, new_remain = remain;
        //     if (pos % 2 == 1 && dgt != d) continue;
        //     if (pos % 2 == 0 && dgt == d) continue;
        //     if (!status && dgt < LMT) new_status = 1;
        //     new_remain = ((new_remain * 10LL) + (dgt - '0')) % m;
        //     ans += call(pos + 1, new_status, new_remain);
        //     ans %= MOD;
        // }
        return dp[pos][status][state] = ans;
        };
    int res = call(0, 0, 0);
    return res;
}

void solve() {
    int a, b, k, d;
    cin >> a >> b >> k >> d;

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