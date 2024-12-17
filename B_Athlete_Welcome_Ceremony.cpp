
/*
    Code by: KoKoDuDu
    Created: 08.12.2024 03:08:53
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;
    //a: 0
    //b: 1
    //c: 2

    while (q--) {   
        int x, y, z;
        cin >> x >> y >> z;
        vector<vector<int>> dp_a(n + 1, vector<int>(max(n, x) + 1, 0));
        vector<vector<int>> dp_b(n + 1, vector<int>(max(n, y) + 1, 0));
        vector<vector<int>> dp_c(n + 1, vector<int>(max(n, z) + 1, 0));
        dp_a[1][1] = (s[1] == 'a' || s[1] == '?');
        dp_b[1][1] = (s[1] == 'b' || s[1] == '?');
        dp_c[1][1] = (s[1] == 'c' || s[1] == '?');
        for (int i = 2; i <= n; ++i) {
            if (s[i] == 'a' || s[i] == '?') {
                for (int j = 1; j <= min(i, x); ++j) {

                    for (int u = 0; u <= min(i, y); ++u) {
                        int c = i - j - u;
                        if (c <= z && c >= 0) dp_a[i][j] += dp_b[i - 1][u] + dp_c[i - 1][i - j - u];
                    }
                }
            }
            if (s[i] == 'b' || s[i] == '?') {
                for (int j = 1; j <= min(i, y); ++j) {
                    for (int u = 0; u <= min(i, z); ++u) {
                        int c = i - j - u;
                        if (c <= z && c >= 0) dp_b[i][j] += dp_a[i - 1][u] + dp_c[i - 1][i - j - u];
                    }
                }
            }
            if (s[i] == 'c' || s[i] == '?') {
                for (int j = 1; j <= min(i, z); ++j) {
                    for (int u = 0; u <= min(i, y); ++u) {
                        int a = i - j - u;
                        if (a <= x && a >= 0) dp_c[i][j] += dp_b[i - 1][u] + dp_a[i - 1][i - j - u];
                    }
                }
            }
            cout << i << " ---\n";
            for (int j = 1; j <= min(x, i); ++j) {
                cout << dp_a[i][j] << ' ';
            }
            cout << "a\n";
            for (int j = 1; j <= min(y, i); ++j) {
                cout << dp_b[i][j] << ' ';
            }
            cout << "b\n";
            for (int j = 1; j <= min(z, i); ++j) {
                cout << dp_c[i][j] << ' ';
            }
            cout << "c\n";
            cout << "-------\n";
        }
    }
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