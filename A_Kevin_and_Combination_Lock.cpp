
/*
    Code by: KoKoDuDu
    Created: 19.12.2024 21:36:42
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    bool isOk = false;
    auto dfs = [&](auto&& dfs, string s, bool& isOk) -> void {
        if (s == "33") {
            isOk = true;
            return;
        }
        bool isUsed = false;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '3' && s[i + 1] == '3') {
                string tmp = s;
                tmp.erase(i, 2);
                isUsed = true;
                dfs(dfs, tmp, isOk);
            }
        }
        if (!isUsed) {
            int x = stoll(s);
            if (x % 33 == 0) {
                isOk = true;
                return;
            }
        }
        if (s == "33") {
            isOk = true;
            return;
        }
        };
    dfs(dfs, s, isOk);
    if (isOk) cout << "YES\n";
    else cout << "NO\n";
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