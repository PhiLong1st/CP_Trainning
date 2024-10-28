

/*
    Code by: KoKoDuDu
    Created: 25.10.2024 22:02:17
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (int j = 0; j < s.size(); j++) {
        cnt[s[j] - 'a']++;
        bool has_zero = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] == 0) {
                has_zero = 1;
            }
            if (cnt[i] != 0 && has_zero)
            {
                cout << "NO";
                return;
            }
        }
    }


    cout << "YES";
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