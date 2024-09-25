/*
    Code by: KoKoDuDu
    Created: 25.09.2024 19:44:44
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int>save;
    unordered_map<int, int> cnt, tmpCnt;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (cnt[x] == 0) {
            save.push_back(x);
        }
        cnt[x]++;
    }
    tmpCnt = cnt;
    sort(save.begin(), save.end());
    vector<int>pre(save.size()), suf(save.size());
    // for (int i : save) {
    //     cout << i << " ";
    // }
    // cout << "\n";
    for (int i = 1; i < save.size(); ++i) {
        pre[i] = (save[i] - save[i - 1]) * cnt[save[i - 1]];
        pre[i] += pre[i - 1];
        cnt[save[i]] += cnt[save[i - 1]];
        // cout << pre[i] << " ";
    }
    // cout << "\n";
    for (int i = (int)save.size() - 2; i >= 0; --i) {
        suf[i] = abs(save[i] - save[i + 1]) * tmpCnt[save[i + 1]];
        suf[i] += suf[i + 1];
        tmpCnt[save[i]] += tmpCnt[save[i + 1]];
        // cout << suf[i] << " ";
        // cout << i << " ";
    }
    int ans = INT_MAX;
    // cout << "\n";
    for (int i = save.size() - 1; i >= 0; --i) {
        if (k < suf[i]) break;
        int pos = upper_bound(pre.begin(), pre.end(), k - suf[i]) - pre.begin() - 1;
        if (pos >= i) {
            ans = 0;
            break;
        }
        if (pos == i) {
            continue;
        }
        int remain = k - suf[i] - pre[pos];
        // cout << suf[i] << " " << pos << " " << save[i] << " " << save[pos] << " " << remain << "\n";
        cout << tmpCnt[save[i]] << " " << cnt[save[pos]] << "\n";
        int bonus;
        if (tmpCnt[save[i]] < cnt[save[pos]]) {
            bonus = min(save[i + 1] - save[i], remain / tmpCnt[save[i]]);
        }
        else {
            bonus = min(save[i] - save[i - 1], remain / cnt[save[pos]]);
        }
        ans = min(ans, max(0LL, save[i] - save[pos] - bonus));
    }
    if (ans == INT_MAX) {
        ans = 0;
    }
    cout << ans;
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