
/*
    Code by: KoKoDuDu
    Created: 02.10.2024 17:18:47
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, u, r, d, l;
    cin >> n >> u >> r >> d >> l;
    for (int state = 0; state < 16; ++state) {
        int tmpU = u, tmpR = r, tmpD = d, tmpL = l;
        bool ok = 0;
        for (int bit = 0; bit < 4; ++bit) {
            int mask = (1 << bit);
            if ((state & mask)) {
                if (bit == 0) {
                    ok |= !(tmpU > 0 && tmpL > 0);
                    tmpU--;
                    tmpL--;
                }
                if (bit == 1) {
                    ok |= !(tmpU > 0 && tmpR > 0);
                    tmpU--;
                    tmpR--;
                }
                if (bit == 2) {
                    ok |= !(tmpD > 0 && tmpR > 0);
                    tmpD--;
                    tmpR--;
                }
                if (bit == 3) {
                    ok |= !(tmpD > 0 && tmpL > 0);
                    tmpD--;
                    tmpL--;
                }
                // cout << bit << " ";
            }
        }
        // cout << "\n";
        // cout << tmpU << " " << tmpR << " " << tmpD << " " << tmpL << "\n";
        if (!ok && max({ tmpU, tmpR, tmpD, tmpL }) <= n - 2) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

/*
01
01
 */
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