

/*
    Code by: KoKoDuDu
    Created: 14.10.2024 22:20:45
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int cnt = 0;
    vector<vector<int>>dp(m + 2, vector<int>(m + 1));
    vector<int>save(m + 1);
    dp[0][0] = 1;
    save[0] = 1;
    for (int i = 1; i <= n; ++i) {
        vector<int>tmpSave(m + 2);
        if (a[i] == 0) {
            for (int j = 0; j <= cnt; ++j) {
                dp[j + 1][cnt - j] = max(dp[j + 1][cnt - j], dp[j][cnt - j]);
                dp[j][cnt - j + 1] = max(dp[j][cnt - j + 1], dp[j][cnt - j]);
                tmpSave[j + 1] = max(tmpSave[j + 1], save[j]);
                tmpSave[cnt - j + 1] = max(tmpSave[cnt - j + 1], save[j]);
            }
            cnt++;
        }
        if (a[i] > 0) {
            for (int j = abs(a[i]); j <= cnt; ++j) {
                dp[j][cnt - j]++;
                save[j]++;
            }
        }
        if (a[i] < 0) {
            for (int j = abs(a[i]); j <= cnt; ++j) {
                dp[cnt - j][j]++;
            }
            for (int j = 0; j <= cnt; ++j) {
                if (cnt - j >= abs(a[i]))
                    save[cnt - j]++;
            }
        }
        cout << i << "a\n";
        for (int j = 0; j <= cnt; ++j) {
            cout << save[j] << "-";
        }
        cout << '\n';
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
    }
    cerr << *max_element(save.begin(), save.end()) - 1;
    cout << ans - 1;
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