
/*
    Code by: KoKoDuDu
    Created: 20.12.2024 19:28:25
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    string s, t;
    cin >> s >> t;
    t = t + " ";
    s = s + " ";
    int pos_1 = 0, pos_2 = 0, type_1 = 0, type_2 = 1;
    int n = t.size();
    bool isOk = false;
    for (int i = 0; i < s.size(); ++i) {
        int rem = i % 2;
        if (type_1 == rem && t[pos_1] == s[i]) {
            pos_1++;
            type_1 = 1 - rem;
        }
        if (type_2 == rem && t[pos_2] == s[i]) {
            pos_2++;
            type_2 = 1 - rem;
        }
        if (max(pos_1, pos_2) == n) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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