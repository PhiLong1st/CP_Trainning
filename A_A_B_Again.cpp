
/*
    Code by: KoKoDuDu
    Created: 17.12.2024 10:15:22
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0;i < s.size(); ++i) {
        sum += s[i] - '0';
    }
    cout << sum << '\n';
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