
/*
    Code by: KoKoDuDu
    Created: 08.12.2024 01:59:08
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
    set<int> save;
    save.insert((int)0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        save.insert(a[i]);
    }
    for (int i = 2; i <= n; ++i) {
        int x = a[i], y = a[i - 1];
        int u = x ^ y;
        int v = x | y;
        int t = x & y;

        save.insert(u);
        save.insert(u & x);
        save.insert(u & y);

        save.insert(v);
        save.insert(v ^ x);
        save.insert(v ^ y);

        save.insert(t);
        save.insert(t ^ x);
        save.insert(t ^ y);
    }
    cout << save.size();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}