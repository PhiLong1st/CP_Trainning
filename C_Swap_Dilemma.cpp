/*
    Code by: KoKoDuDu
    Created: 21.09.2024 06:13:37
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    map<int, int>check;
    vector<int> c(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        check[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    c = a;
    d = b;
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    if (c != d) {
        return void(cout << "NO\n");
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (check[b[i]] != (i));
    }
    if (ans == 0 || ans % 2 != 0) {
        cout << "YES\n";
    }
    else {
        if (ans == 2) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
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