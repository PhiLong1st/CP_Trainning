
/*
    Code by: KoKoDuDu
    Created: 29.12.2024 16:56:28
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> fibo(n + 2);
    fibo[0] = fibo[1] = 1;
    for (int i = 2; i <= n + 1; ++i) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    while (n) {
        int new_x, new_y;
        y = min(y, 1 + fibo[n + 1] - y);
        new_x = y;
        new_y = 1 + fibo[n] - x;
        if (y > fibo[n - 1]) {
            break;
        }
        x = new_x;
        y = new_y;
        if (n == 1) {
            if (x == 1 && y == 1) {
                cout << "YES\n";
                return;
            }
            if (x == 1 && y == 2) {
                cout << "YES\n";
                return;
            }
        }
        n--;
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