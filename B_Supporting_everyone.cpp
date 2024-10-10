
/*
    Code by: KoKoDuDu
    Created: 29.09.2024 17:37:23
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(m + 1), isDelete(n + 1);
    queue<int>que;
    vector<vector<int>>save(n + 1, vector<int>());
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int c;
            cin >> c;
            save[i].push_back(c);
            cnt[c]++;
        }
    }
    for (int num = 1; num <= n; ++num) {
        set<int>s;
        for (int i = 1; i <= n; ++i) {
            if (isDelete[i]) continue;
            for (int c : save[i]) {
                if (cnt[c] == 1) {
                    s.insert(i);
                }
            }
        }
        if (s.empty()) break;
        for (int i : s) {
            isDelete[i] = 1;
            for (int c : save[i]) {
                cnt[c]--;
            }
            ans++;
        }
    }
    int dem1 = 0, dem2 = 0;
    for (int i = 1; i <= n; ++i) {
        dem2 += (isDelete[i] == 0);
    }

    for (int i = 1; i <= m; ++i) {
        dem1 += (cnt[i] > 0);
    }
    cout << min({ n, m, ans + min(dem1, dem2) });
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