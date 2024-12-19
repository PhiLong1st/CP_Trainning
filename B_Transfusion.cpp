
/*
    Code by: KoKoDuDu
    Created: 18.12.2024 04:33:47
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
    for (auto& c : a) cin >> c;
    int sume = 0, sumo = 0;
    int lene = 0, leno = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            sume += a[i];
            lene++;
        }
        else {
            sumo += a[i];
            leno++;
        }
    }
    if (sumo % leno != 0 || sume % lene != 0) {
        cout << "NO\n";
        return;
    }
    sumo /= leno;
    sume /= lene;
    cout << (sume == sumo ? "YES" : "NO") << '\n';
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