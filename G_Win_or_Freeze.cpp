
/*
    Code by: KoKoDuDu
    Created: 29.12.2024 15:35:51
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    vector<int> save;
    int tmp = n;
    if (n == 1) {
        cout << 1 << "\n" << 0;
        return;
    }
    for (int i = 2; i * i <= tmp; ++i) {
        if (n % i == 0) {
            save.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n != 1) save.push_back(n);
    cnt = save.size();
    if (cnt == 2) {
        if (save[0] * save[1] == tmp) {
            cout << 2;
        }
        else {
            cout << 1 << "\n" << save[0] * save[1];
        }
    }
    else if (cnt == 1) {
        if (save[0] == tmp) {
            cout << 1 << "\n" << 0;
        }
        else  if (save[0] * save[0] == tmp) {
            cout << 2;
        }
        else {
            cout << 1 << "\n" << save[0] * save[0];
        }
    }
    else {
        cout << "1\n";
        cout << save[0] * save[1];
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