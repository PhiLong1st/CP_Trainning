/*
    Code by: KoKoDuDu
    Created: 20.10.2024 10:28:42
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long 
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
    vector<vector<vector<vector<int>>>>st(LGMN, vector<vector<vector<int>>>(n + 1, vector<vector<int>>(LGMN, vector<int>(n + 1))));
    for (int k = 0; k < LGMN; ++k) {
        for (int i = 1; i + (1 << k) - 1 <= n; ++i) {
            for (int l = 0; l < LGMN; ++l) {
                for (int j = 1; j + (1 << l) - 1 <= n; ++j) {
                    if (k == 0) {
                        if (l == 0) {
                            st[0][i][0][j] = a[i][j];
                        }
                        else {
                            st[0][i][l][j] = max(st[0][i][l - 1][j], st[0][i][l - 1][j + (1 << (l - 1))]);
                        }
                    }
                    else {
                        st[k][i][l][j] = max(st[k - 1][i][l][j], st[k - 1][i + (1 << (k - 1))][l][j]);
                    }
                }
            }
        }
    }
    function<int(int, int, int, int)> get_max = [&](int x, int y, int a, int b) {
        int k = __lg(a - x + 1);
        int l = __lg(b - y + 1);
        return max({ st[k][x][l][b - (1 << l) + 1], st[k][x][l][y], st[k][a - (1 << k) + 1][l][y],
st[k][a - (1 << k) + 1][l][b - (1 << l) + 1]
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
