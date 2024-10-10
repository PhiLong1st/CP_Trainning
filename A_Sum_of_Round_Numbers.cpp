
/*
    Code by: KoKoDuDu
    Created: 29.09.2024 19:46:48
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    string n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n.size(); ++i) {
        ans += (n[i] != '0');
    }
    cout << ans << "\n";
    for (int i = 0; i < n.size(); ++i) {
        if (n[i] != '0') {
            cout << (n[i] - '0') * pow(10LL, (int)n.size() - 1 - i) << " ";
        }
    }
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    cin >> numTest;
    while (numTest--) {
        solve();
    }
    return 0;
}