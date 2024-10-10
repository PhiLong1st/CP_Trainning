
/*
    Code by: KoKoDuDu
    Created: 29.09.2024 14:57:50
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<string> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> save(4);
    int ans = 0;
    vector<char> c = { 'S', 'W', 'E', 'R' };
    for (int i = 0; i < 4; ++i) {
        save[i] = i;
    }
    do {
        int tmp = 0;
        for (int i : save) {
            cout << i << ' ';
        }
        for (int i = 1; i <= n; ++i) {
            if (a[i][0] == 'C') continue;

        }
        cout << '\n';
    } while (next_permutation(save.begin(), save.end()));
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