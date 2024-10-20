/*
    Code by: KoKoDuDu
    Created: 20.10.2024 01:00:21
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

bool check(int x, int len) {
    string s = to_string(x);
    if (s.size() != len) return false;
    int n = s.size();
    for (int i = 1; i < n; ++i) {
        if (abs(s[i] - s[i - 1]) != 1) return false;
    }
    return true;
}
string to_string(int x) {
    return to_string(x);
}
void solve() {
    int l, r, m;
    cin >> l >> r >> m;
    int l_sz = (to_string(l).size() + 1) / 2;
    int r_sz = (to_string(r).size() + 1) / 2;
    vector<int> save;
    for (int len = l_sz; len <= r_sz; ++len) {
        for (int s = 1; s <= 9; ++s) {
            int num = s;
            for (int i = 1; i < len; ++i) {
                if (s + i <= 9) {
                    num = num * 10 + (s + i);
                }
                else {
                    break;
                }
            }
            for (int i = len - 1; i >= 1; --i) {
                num = num * 10 + (s + i - 1);
            }
            if (num >= l && num <= r && check(num, 2 * len - 1)) {
                save.push_back(num);
            }
        }
    }
    sort(save.begin(), save.end());
    int ans = 0;
    for (int num : save) {
        if (num % m == 0) {
            ans++;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
