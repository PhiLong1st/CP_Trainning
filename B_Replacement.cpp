
/*
    Code by: KoKoDuDu
    Created: 09.11.2024 22:14:51
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int num_1 = 0, num_2 = 0;
    for (int i = 0; i < s.size(); ++i) {
        num_1 += (s[i] == '1');
    }
    if (num_1 == 0 || num_1 == n) return void(cout << "NO\n");
    int x = num_1, y = n - num_1;
    for (int i = 0; i < t.size(); ++i) {
        if (x == 0 || y == 0)  return void(cout << "NO\n");
        y -= (t[i] == '1');
        x -= (t[i] == '0');
    }
    cout << "YES\n";
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