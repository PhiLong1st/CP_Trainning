
/*
    Code by: KoKoDuDu
    Created: 23.09.2024 15:15:31
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0, maxx = 0;
    maxx = *max_element(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (ans < 0) {
            ans = 0;
        }
        ans += a[i];
        maxx = max(maxx, ans);
    }
    cout << maxx;

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