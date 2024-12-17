
/*
    Code by: KoKoDuDu
    Created: 17.12.2024 11:46:57
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    function < int(int, int)> ask = [&](int a, int b) {
        cout << "? " << a << " " << b << "\n";
        cout.flush();
        int x;
        cin >> x;
        return x;
        };
    int l = 2, r = 999;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (ask(1, mid) > mid) {
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << "! " << ans << '\n';
    cout.flush();
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