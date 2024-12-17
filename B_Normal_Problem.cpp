
/*
    Code by: KoKoDuDu
    Created: 15.12.2024 21:39:13
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'p') cout << 'q';
        if (s[i] == 'q') cout << 'p';
        if (s[i] == 'w') cout << 'w';
    }
    cout << '\n';
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