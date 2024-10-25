

/*
    Code by: KoKoDuDu
    Created: 24.10.2024 10:45:34
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
int cal(string num, int m, char d) {
    vector<vector<vector<int>>> dp(2002, vector<vector<int>>(2, vector<int>(2001, -1)));
    function<int(int, int, int)> call = [&](int pos, int status, int remain) {
        if (pos == (int)num.size()) {
            return (int)(remain == 0);
        }
        if (dp[pos][status][remain] != -1) {
            return dp[pos][status][remain];
        }
        int ans = 0;
        char LMT = '9';
        if (status == 0) {
            LMT = num[pos];
        }
        char st = '0';
        for (char dgt = '0'; dgt <= LMT; dgt++) {
            int new_status = status, new_remain = remain;
            if (pos % 2 == 1 && dgt != d) continue;
            if (pos % 2 == 0 && dgt == d) continue;
            if (!status && dgt < LMT) new_status = 1;
            new_remain = ((new_remain * 10LL) + (dgt - '0')) % m;
            ans += call(pos + 1, new_status, new_remain);
            ans %= MOD;
        }
        return dp[pos][status][remain] = ans;
        };
    int res = call(0, 0, 0);
    return res;
}
void solve() {
    int m;
    char d;
    string l, r;
    cin >> m >> d >> l >> r;
    int bonus = 1;
    int du = 0;
    for (int i = 0; i < l.size(); i++) {
        if (i % 2) {
            bonus &= ((int)(l[i]) == d);
        }
        else {
            bonus &= ((int)(l[i]) != d);
        }
        du = (du * 10 + (l[i] - '0')) % m;
    }
    bonus &= (du == 0);
    cout << (cal(r, m, d) - cal(l, m, d) + bonus + MOD) % MOD;
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