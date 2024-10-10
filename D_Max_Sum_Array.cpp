
/*
    Code by: KoKoDuDu
    Created: 28.09.2024 15:28:39
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

int power(int x, int y, int p) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int modInverse(int n, int p) {
    return power(n, p - 2, p);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), inv(1000001, 1), gt(1000001, 1);
    for (int i = 1; i <= 1000000; ++i) {
        gt[i] = (gt[i - 1] * i) % MOD;
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin() + 1, a.end(), greater<>());
    int ans = 0;
    for (int i = 1; i <= sum; ++i) {
        for (int j = sum; j >= 1; --j) {
            ans += (j - 1) * (sum - i + 1);
            ans %= MOD;
        }
    }
    int res = 0;
    for (int i = 1; i <= sum; ++i) {
        for (int j = 0; j < sum; ++j) {
            res += j * (sum - i + 1);
            res %= MOD;
        }
    }
    cout << (ans - res + MOD) % MOD;
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