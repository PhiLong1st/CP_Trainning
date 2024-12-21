
/*
    Code by: KoKoDuDu
    Created: 19.12.2024 22:43:38
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }
    int val = a[1];
    sort(b.begin() + 1, b.end());
    sort(a.begin() + 1, a.end());
    // for (int i = 1; i <= n; ++i) {
    //     cerr << a[i] << ' ';
    // }
    // cerr << '\n';
    // for (int i = 1; i <= m; ++i) {
    //     cerr << b[i] << ' ';
    // }
    vector<int> save;
    for (int i = 1; i <= m; ++i) {
        if (b[i] <= val) {
            save.push_back(0);
        }
        else {
            int pos = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
            save.push_back(n - pos + 1);
        }
    }
    sort(save.begin(), save.end());
    vector<vector<int>> f(20, vector<int>(m + 1));
    for (int i = 1; i <= m; ++i) f[0][i] = save[i - 1];
    for (int i = 1; i < 20; ++i) {
        for (int j = 1; j <= m; ++j) {
            f[i][j] = f[i - 1][j];
            if (j + (1 << (i - 1)) <= m) f[i][j] = max(f[i][j], f[i - 1][j + (1 << (i - 1))]);
        }
    }
    auto get_max = [&](int l, int r) -> int {
        int len = r - l + 1;
        int k = 31 - __builtin_clz(len);
        return max(f[k][l], f[k][r - (1 << k) + 1]);
        };
    for (int i = 1; i <= m; ++i) {
        int tmp = 0;
        for (int j = i; j <= m; j += i) {
            tmp += (int)get_max(j - i + 1, j) + 1;
        }
        cout << tmp << ' ';
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