
/*
    Code by: KoKoDuDu
    Created: 18.12.2024 04:36:03
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
    for (int i = 1; i < s.size(); ++i) {
        int id = i;
        while (id > 0 && s[id] > s[id - 1] + 1) {
            s[id]--;
            swap(s[id], s[id - 1]);
            id--;
        }
    }
    cout << s << '\n';
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