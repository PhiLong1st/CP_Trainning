
/*
    Code by: KoKoDuDu
    Created: 16.12.2024 16:10:34
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> ans;
    while (n--) {
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '#') {
                ans.push_back(i + 1);
            }
        }
    }
    for (int i = ans.size() - 1; i >= 0; --i) {
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
    while (t--) {
        solve();
    }
    return 0;
}