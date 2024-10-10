
/*
    Code by: KoKoDuDu
    Created: 29.09.2024 22:51:06
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 1 || k > n)
    {
        cout << n << "\n";
        return;
    }
    int res = 0;
    while (n > 0)
    {
        if (n < k) {
            res += n;
            break;
        }
        int mul = 1;
        while (mul <= n)
        {
            mul *= k;
        }
        mul /= k;
        res++;
        n -= mul;
    }
    cout << res << endl;
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