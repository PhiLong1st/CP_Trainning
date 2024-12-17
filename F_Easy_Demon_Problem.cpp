
/*
    Code by: KoKoDuDu
    Created: 15.12.2024 22:58:22
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    int suma = 0, sumb = 0;
    unordered_map<int, int> checka, checkb;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        suma += a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        sumb += b[i];
    }
    for (int i = 1; i <= n; ++i) {
        checka[suma - a[i]] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        checkb[sumb - b[i]] = 1;
    }
    while (q--) {
        int x;
        cin >> x;
        bool isOk = false;
        for (int i = 1; i * i <= abs(x); ++i) {
            if (abs(x) % i == 0) {
                isOk |= ((checka[x / i] == 1) && (checkb[i] == 1));
                isOk |= ((checka[i] == 1) && (checkb[x / i] == 1));
                isOk |= ((checka[x / -i] == 1) && (checkb[-i] == 1));
                isOk |= ((checka[-i] == 1) && (checkb[x / -i] == 1));
            }
        }
        if (isOk) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
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