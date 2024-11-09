
/*
    Code by: KoKoDuDu
    Created: 01.11.2024 22:12:36
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    int ans = INF;
    for (int i = 1; i <= n - 1; ++i) {
        int ans_L = 0, ans_R = n - i - 1;
        int ans_Tmp = 0;
        while (ans_L <= ans_R) {
            int ans_Mid = (ans_L + ans_R) >> 1;
            int l = i + 1, r = n;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (mid - i == 1) break;
                int pos = upper_bound(a.begin() + i + 1, a.begin() + mid, a[mid] - a[i]) - a.begin() - 1 - i;
                if (mid - pos + 1 >= ans_Mid) {
                    ans_Tmp = max(ans_Tmp, mid - pos + 1);
                    break;
                }
                else {
                    
                }
            }
            // ans = min(ans, i - 1 + pos - i + 1 + n - mid);
        }
    }
    cout << ans << '\n';
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