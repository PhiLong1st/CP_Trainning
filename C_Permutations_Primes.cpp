
/*
    Code by: KoKoDuDu
    Created: 29.12.2024 14:34:19
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
const int maxN = 2e5 + 0307;
int isPrime[maxN];
void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    if (n == 2) {
        cout << 1 << ' ' << 2 << '\n';
        return;
    }
    vector<int> ans(n + 1), save, cnt(n + 1);
    ans[(n + 1) / 2] = 1;
    cnt[1] = 1;
    for (int i = n; i >= 1; --i) {
        if (isPrime[i]) continue;
        // cout << i << ' ';
        save.push_back(i);
    }
    int pre = 1, suf = n;
    for (int i = 0; i < save.size(); ++i) {
        if (i % 2 == 0) {
            ans[pre] = save[i];
            cnt[save[i]] = 1;
            pre++;
        }
        else {
            ans[suf] = save[i];
            cnt[save[i]] = 1;
            suf--;
        }
        // cout << save[i] << ' ';
    }
    vector<int> tmp;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i]) continue;
        tmp.push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (ans[i]) continue;
        if (tmp.empty()) break;
        ans[i] = tmp.back();
        tmp.pop_back();
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    isPrime[1] = 1;
    for (int i = 2; i < maxN; ++i) {
        if (isPrime[i]) continue;
        for (int j = i * i; j < maxN; j += i) {
            isPrime[j] = 1;
        }
    }
    while (t--) {
        solve();
    }
    return 0;
}