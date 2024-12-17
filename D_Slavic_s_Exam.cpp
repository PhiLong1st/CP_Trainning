
/*
    Code by: KoKoDuDu
    Created: 17.12.2024 11:29:08
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    string s, t;
    cin >> s >> t;
    int pos = 0;
    string ans = "";
    for (int i = 0; i < s.size(); ++i) {

        if (pos == t.size() && s[i] == '?') {
            ans += "a";
            continue;
        }
        if (pos < t.size() && s[i] == '?') {
            ans += t[pos];
            pos++;
            continue;
        }
        if (pos < t.size() && s[i] == t[pos]) {
            pos++;
        }
        ans += s[i];
    }
    if (pos == t.size()) {
        cout << "YES\n";
        cout << ans << '\n';
    }
    else {
        cout << "NO\n";
    }
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