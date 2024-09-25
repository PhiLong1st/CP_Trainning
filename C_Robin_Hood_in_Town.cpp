/*
    Code by: linvg
    Created: 21.09.2024 22:15:31
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int>a(n + 1);
    int sum = 0, maxx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        if (a[maxx] < a[i]) {
            maxx = i;
        }
    }
    int l = 0, r = 1e12, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int cnt = 0;
        a[maxx] += mid;
        for (int i = 1; i <= n; i++) {
            if (a[i] * 2 * n < sum + mid) {
                cnt++;
            }
        }
        a[maxx] -= mid;
        if (cnt * 2 <= n) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
            ans = mid;
        }
    }
    cout << ans << "\n";
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