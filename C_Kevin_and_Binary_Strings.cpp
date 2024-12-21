
/*
    Code by: KoKoDuDu
    Created: 19.12.2024 21:56:08
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n = (int)s.size();
    int pos = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            pos = n - i;
            break;
        }
    }
    if (pos == 0) {
        cout << 1 << ' ' << n << ' ' << n << ' ' << n << '\n';
        return;
    }
    string suf = s.substr(n - pos, pos);
    string ans = suf;
    int x = -1, y = -1;
    for (int i = 0; i < n - pos + 1; ++i) {
        string tmp = s.substr(i, pos);
        for (int j = 0; j < tmp.size(); ++j) {
            if (tmp[j] == suf[j] && tmp[j] == '1') {
                tmp[j] = '0';
                continue;
            }
            if (tmp[j] != suf[j]) {
                tmp[j] = '1';
            }
        }
        if (ans < tmp) {
            ans = tmp;
            x = i, y = i + pos - 1;
        }
    }
    cout << 1 << ' ' << n << ' ' << x + 1 << ' ' << y + 1 << '\n';
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