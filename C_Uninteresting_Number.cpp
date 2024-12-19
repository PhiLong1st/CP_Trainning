
/*
    Code by: KoKoDuDu
    Created: 18.12.2024 04:35:24
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int cnt2 = 0, cnt3 = 0;
    int digit = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '2') cnt2++;
        else if (s[i] == '3') cnt3++;
        digit += s[i] - '0';
    }
    digit %= 9;
    for (int i = 0; i <= cnt2; ++i) {
        int addup = 2 * i;
        int remain = (digit + addup) % 9;
        if (remain == 0) {
            cout << "YES\n";
            return;
        }
        if (remain == 3) {
            if (cnt3 > 0) {
                cout << "YES\n";
                return;
            }
        }
        if (remain == 6) {
            if (cnt3 > 1) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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