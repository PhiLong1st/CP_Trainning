
/*
    Code by: KoKoDuDu
    Created: 30.12.2024 14:32:37
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), save, pf, pf_val;
    map<int, int> cnt, tmpCnt;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
        tmpCnt[a[i]]++;
        if (cnt[a[i]] == 1) {
            save.push_back(a[i]);
        }
    }
    int remain = k;
    sort(save.begin(), save.end());
    for (int i = 0; i < save.size(); ++i) {
        if (i == 0) {
            pf.push_back(cnt[save[i]]);
            pf_val.push_back(cnt[save[i]] * save[i]);
        }
        else {
            pf.push_back(pf.back() + cnt[save[i]]);
            pf_val.push_back(pf_val.back() + cnt[save[i]] * save[i]);
        }
    }
    int ans = 1e18;
    for (int i = 0; i < save.size(); ++i) {
        if (i != 0) {
            remain -= cnt[save[i - 1]] * (save[i] - save[i - 1]);
            cnt[save[i]] += cnt[save[i - 1]];
        }
        // cout << remain << ' ';
        if (remain <= 0) {
            break;
        }
        int l = save[i], r = save.back();
        int res = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int pos = upper_bound(save.begin(), save.end(), mid) - save.begin();
            int used = (pf_val[save.size() - 1] - pf_val[pos - 1]) - mid * (pf[save.size() - 1] - pf[pos - 1]);
            if (used <= remain) {
                ans = min(ans, mid - save[i]);
                r = mid - 1;
                res = mid;
            }
            else {
                l = mid + 1;
            }
        }
        // cout << res << '\n';
    }
    remain = k;
    for (int i = save.size() - 1; i >= 0; --i) {
        if (i != save.size() - 1) {
            remain -= tmpCnt[save[i + 1]] * (save[i + 1] - save[i]);
            tmpCnt[save[i]] += tmpCnt[save[i + 1]];
        }
        if (remain <= 0) {
            break;
        }
        // cout << remain << ' ';
        int l = save[0], r = save[i];
        int res = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int pos = upper_bound(save.begin(), save.end(), mid) - save.begin();
            int used = pf_val[pos - 1] - mid * pf[pos - 1];
            if (-used <= remain) {
                ans = min(ans, save[i] - mid);
                l = mid + 1;
                res = mid;
            }
            else {
                r = mid - 1;
            }
        }
        // cout << res << '\n';
    }
    cout << ans;
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