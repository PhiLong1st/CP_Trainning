
/*
    Code by: KoKoDuDu
    Created: 01.10.2024 18:02:28
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<pll>a(n + 1);
    vector<vector<int>> save_A(200001, vector<int>()), save_B(200001, vector<int>());
    map<int, int> cnt_A, cnt_B;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
        save_A[a[i].first].push_back(a[i].second);
        save_B[a[i].second].push_back(a[i].first);
        cnt_B[a[i].second]++;
        cnt_A[a[i].first]++;

    }
    int ans = n * (n - 1) * (n - 2) / 6;
    int res = 0;
    for (int i = 1; i <= 200000; ++i) {
        int cnt = save_A[i].size();
        if (save_A[i].size() <= 1) continue;
        int  sz = save_A[i].size() - 1;
        for (int x = 0; x < save_A[i].size(); ++x) {
            ans -= (sz - x) * (n - cnt_B[save_A[i][x]]) - x * cnt_B[save_A[i][x]];
            ans -= (sz - x) * (cnt_B[save_A[i][x]] - 2) + x * cnt_B[save_A[i][x]];
            res += (sz - x) * (n - cnt_B[save_A[i][x]]) - x * cnt_B[save_A[i][x]];
            // for (int y = x + 1; y < save_A[i].size(); ++y) {
            //     ans -= n - cnt_B[save_A[i][x]] - cnt_B[save_A[i][y]];
            //     ans -= cnt_B[save_A[i][x]] + cnt_B[save_A[i][y]] - 2;
            //     res += n - cnt_B[save_A[i][x]] - cnt_B[save_A[i][y]];
            // }
        }
    }
    for (int i = 1; i <= 200000; ++i) {
        int cnt = save_B[i].size();
        if (save_B[i].size() <= 1) continue;
        int  sz = save_B[i].size() - 1;
        for (int x = 0; x < save_B[i].size() - 1; ++x) {
            ans -= (sz - x) * (n - cnt_A[save_B[i][x]]) - x * cnt_A[save_B[i][x]];
            res += (sz - x) * (n - cnt_A[save_B[i][x]]) - x * cnt_A[save_B[i][x]];
            // for (int y = x + 1; y < save_B[i].size(); ++y) {
            //     ans -= n - cnt_A[save_B[i][x]] - cnt_A[save_B[i][y]];
            //     // ans -= cnt_A[save_B[i][x]] + cnt_A[save_B[i][y]];
            //     res += n - cnt_A[save_B[i][x]] - cnt_A[save_B[i][y]];
            // }
        }
    }
    cout << ans + res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    while (numTest--) {
        solve();
    }
    return 0;
}