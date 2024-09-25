/*
    Code by: linvg
    Created: 21.09.2024 21:46:12
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    int sum = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x >= k) {
            sum += x;
        }
        else if (x == 0) {
            if (sum > 0) {
                cnt++;
                sum--;
            }
        }
    }
    cout << cnt << "\n";
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