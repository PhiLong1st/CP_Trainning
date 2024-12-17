
/*
    Code by: KoKoDuDu
    Created: 17.12.2024 11:11:45
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

struct Combinatorics {
    int n, MOD;
    vector<int> fact, inv, fact_inv;

    Combinatorics(int n, int MOD) : n(n), MOD(MOD), fact(n + 1), inv(n + 1), fact_inv(n + 1) {
        inv[1] = 1;
        for (int i = 2; i <= n; ++i) {
            inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
        }

        fact[0] = fact_inv[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fact[i] = fact[i - 1] * i % MOD;
            fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
        }
    }

    int get_nCk(int n, int k) {
        if (n < 0 || k < 0 || n < k) return 0;
        return fact[n] * fact_inv[k] % MOD * fact_inv[n - k] % MOD;
    }
    int get_inv_fact(int i) {
        return fact_inv[i];
    }
    int get_fact(int i) {
        return fact[i];
    }
    int get_inv(int i) {
        return inv[i];
    }
};
Combinatorics comb(200010, MOD);
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    int cnt = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt += a[i];
    }
    int ans = 0;
    for (int i = (k + 1) / 2; i <= k; ++i) {
        ans += comb.get_nCk(cnt, i) * comb.get_nCk(n - cnt, k - i) % MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
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