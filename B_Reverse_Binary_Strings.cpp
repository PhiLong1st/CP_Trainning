
/*
    Code by: KoKoDuDu
    Created: 16.12.2024 15:26:27
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    function <int(string s)> calc = [&](string s) {
        int ans = 0;
        for (int i = 1; i < s.size(); ++i) {
            ans += s[i] == s[i - 1];
        }
        return ans / 2;
        };
    cout << min(calc("1" + s + "0"), calc("0" + s + "1")) << '\n';
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