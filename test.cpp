/*
    Code by: KoKoDuDu
    Created: 20.10.2024 10:28:42
*/
#include <bits/stdc++.h>
using namespace std;
#define pll pair<int, int>
const int MOD = 1e9 + 7;

void solve() {
    int n, k, s;
    cin >> n >> k >> s;

    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int LGMN = __lg(n) + 1;
    vector<vector<vector<vector<int>>>> st(LGMN, vector<vector<vector<int>>>(n + 1, vector<vector<int>>(LGMN, vector<int>(n + 1))));

    for (int x_len = 0; x_len < LGMN; ++x_len) {
        for (int i = 1; i + (1 << x_len) - 1 <= n; ++i) {
            for (int y_len = 0; y_len < LGMN; ++y_len) {
                for (int j = 1; j + (1 << y_len) - 1 <= n; ++j) {
                    if (x_len == 0) {
                        if (y_len == 0) {
                            st[0][i][0][j] = a[i][j];
                        }
                        else {
                            st[0][i][y_len][j] = max(st[0][i][y_len - 1][j], st[0][i][y_len - 1][j + (1 << (y_len - 1))]);
                        }
                    }
                    else {
                        st[x_len][i][y_len][j] = max(st[x_len - 1][i][y_len][j], st[x_len - 1][i + (1 << (x_len - 1))][y_len][j]);
                    }
                }
            }
        }
    }

    auto get_max = [&](int x1, int y1, int x2, int y2) {
        int x_len = __lg(x2 - x1 + 1);
        int y_len = __lg(y2 - y1 + 1);
        return max({
            st[x_len][x1][y_len][y1],
            st[x_len][x1][y_len][y2 - (1 << y_len) + 1],
            st[x_len][x2 - (1 << x_len) + 1][y_len][y1],
            st[x_len][x2 - (1 << x_len) + 1][y_len][y2 - (1 << y_len) + 1]
            });
        };

    for (int i = k; i <= n; i += s) {
        for (int j = k; j <= n; j += s) {
            cout << get_max(i - k + 1, j - k + 1, i, j) << ' ';
        }
        cout << '\n';
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
