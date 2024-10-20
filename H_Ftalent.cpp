

/*
    Code by: KoKoDuDu
    Created: 20.10.2024 08:28:58
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, f, k;
    cin >> n >> f >> k;
    vector<pll> a(n + 1);
    map<int, int >cnt;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        cnt[a[i].first]++;
    }
    if (k == n) {
        cout << "YES\n";
        return;
    }
    int val = a[f].first;
    sort(a.begin() + 1, a.end(), greater<>());
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i].first << ' ';
    // }
    if (a[k].first < val) { 
        cout << "YES\n";
    }
    else if (a[k].first == val) {
        if (a[k + 1].first != val) {
            cout << "YES\n";
        }
        else {
            cout << "MAYBE\n";
        }
    }
    else {
        cout << "NO\n";
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