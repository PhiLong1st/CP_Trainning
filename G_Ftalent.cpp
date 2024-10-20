

/*
    Code by: KoKoDuDu
    Created: 20.10.2024 08:40:38
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    map<int, int>cnt;
    vector<int>ok(30, INT_MAX);
    for (int i = 1; i <= n; ++i) {
        char s;
        cin >> s;
        int t;
        cin >> t;
        ok[s - 'a'] = 0;
        cnt[s - 'a'] = t;

    }
    int ans = 0;
    for (int i = 0;i < s.size(); ++i) {
        if (ok[s[i] - 'a'] == 0) {
            ans++;
            ok[s[i] - 'a'] = cnt[s[i] - 'a'] - 1;
        }
        if (ok[s[i] - 'a']) {
            ans++;
            ok[s[i] - 'a']--;
        }
        // cout << ans << ' ';
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