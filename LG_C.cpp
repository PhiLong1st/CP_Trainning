

/*
    Code by: KoKoDuDu
    Created: 12.10.2024 09:08:18
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cnt_A(n + 1), cnt_B(m + 1);
    vector<vector<int>> save_B(m + 1, vector<int>());
    vector<pll> save_res;
    map<int, int> check_A, check_B;
    for (int i = 1; i <= k; ++i) {
        int u, v;
        cin >> u >> v;
        cnt_A[u]++;
        cnt_B[v]++;
        save_B[v].push_back(u);
    }
    for (int i = 1; i <= m; i++) {
        if ((int)save_B[i].size() == 0) continue;
        for (int g : save_B[i]) {
            save_res.push_back({ cnt_A[g], cnt_B[i] });
        }
    }
    sort(cnt_A.begin() + 1, cnt_A.end());
    sort(cnt_B.begin() + 1, cnt_B.end());
    int ans1 = 0, tmpN = n, tmpM = m;
    for (int i = (int)cnt_A.size() - 1; i >= 0; --i) {
        ans1 += cnt_A[i] * tmpN;
        check_A[cnt_A[i]] = tmpN;
        tmpN--;
    }
    for (int i = (int)cnt_B.size() - 1; i >= 0; --i) {
        ans1 += cnt_B[i] * tmpM;
        check_B[cnt_B[i]] = tmpM;
        tmpM--;
    }
    int minn = 1e18;
    for (auto e : save_res) {
        minn = min(minn, check_A[e.first] + check_B[e.second]);
    }
    cout << ans1 << " " << ans1 - minn << "\n";
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