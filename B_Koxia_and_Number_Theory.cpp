

/*
    Code by: KoKoDuDu
    Created: 11.10.2024 14:58:08
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int cnt_even = 0, cnt_odd = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt_even += !(a[i] % 2);
        cnt_odd += (a[i] % 2);
    }
    if (min(cnt_even, cnt_odd) > 1) {
        return void(cout << "NO\n");
    }
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (a[i] == a[j]) {
                return void(cout << "NO\n");
            }
        }
    }
    for (int i = 2; i <= 100; ++i) {
        vector<int>save(i);
        for (int j = 1; j <= n; ++j) {
            save[a[j] % i]++;
        }
        if (*min_element(save.begin(), save.end()) > 1) {
            return void(cout << "NO\n");
        }
    }
    cout << "YES\n";
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