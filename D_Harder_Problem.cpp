
/*
    Code by: KoKoDuDu
    Created: 15.12.2024 21:49:18
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> cnt, used;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt[a[i]] = 1;
    }
    vector<int> save;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i]) continue;
        save.push_back(i);
    }
    int pos = 0;
    for (int i = 1; i <= n; ++i) {
        if (used[a[i]] == 1) {
            cout << save[pos++] << ' ';
        }
        else {
            cout << a[i] << ' ';
        }
        used[a[i]] = 1;
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