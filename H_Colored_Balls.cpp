
/*
    Code by: KoKoDuDu
    Created: 01.10.2024 16:57:39
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    if (a[0] == 0 && a[1] == 0) {
        cout << -1;
        return;
    }
    sort(a.begin(), a.end());
    if (a[0] % 2 == a[1] % 2 && a[1] % 2 == a[2] % 2) {
        int step = (a[1] - a[0]) / 2;
        int ans1 = step + (a[2] - step - a[0] - step);
        step = (a[2] - a[1]);
        int ans2 = step + (a[1] - a[0]) / 2;
        cout << min(ans1, ans2);
    }
    else {
        cout << -1;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    while (numTest--) {
        solve();
    }
    return 0;
}