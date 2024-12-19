
/*
    Code by: KoKoDuDu
    Created: 18.12.2024 11:54:39
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    int val = 1;
    if (n == 1 && k == 1) {
        cout << 1 << '\n';
        return;
    }
    bool isOk = false;
    for (int i = 1; i <= n - 1; ++i) {
        val *= 2;
        if (val >= k) {
            isOk = true;
            break;
        }
    }
    if (!isOk) {
        cout << -1 << '\n';
    }
    else {
        deque <int> save;
        save.push_back(n);
        int tmp = k;
        int pos = n;
        for (int i = 1; i <= n - 1; ++i) {
            int val = (tmp + 1) / 2;
            if (tmp == val * 2) {
                save.push_front(--pos);
            }
            else {
                save.push_back(--pos);
            }
            tmp = (tmp + 1) / 2;
        }
        reverse(save.begin(), save.end());
        for (int x : save) {
            cout << x << ' ';
        }
        cout << '\n';
    }
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