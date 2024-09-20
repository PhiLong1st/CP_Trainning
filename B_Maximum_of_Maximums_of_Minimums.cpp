/*
    Code by: KoKoDuDu
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (k == 1) {
        cout << *min_element(a.begin() + 1, a.end());
        return;
    }
    if (k == 2) {
        vector<int> save(n + 1);
        save[n] = a[n];
        for (int i = n - 1; i >= 1; i--) {
            save[i] = min(save[i + 1], a[i]);
        }
        int minn = INT_MAX, ans = -INT_MAX;
        for (int i = 1; i < n; i++) {
            minn = min(minn, a[i]);
            ans = max(ans, max(minn, save[i + 1]));
        }
        cout << ans << "\n";
        return;
    }
    cout << *max_element(a.begin() + 1, a.end());

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