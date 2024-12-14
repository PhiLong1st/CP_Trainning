
/*
    Code by: KoKoDuDu
    Created: 05.12.2024 21:35:18
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    int res = 0;
    int len = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        len += s[i].size();
        if (len <= m) res = i + 1;
    }
    cout << res << '\n';
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