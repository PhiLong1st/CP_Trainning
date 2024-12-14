#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

struct NumberTheory {
    // Calculate modular inverse using Extended Euclidean algorithm
    int inverse(int i, int MOD) {
        if (i == 1) return 1;
        return (MOD - (MOD / i) * inverse(MOD % i, MOD) % MOD + MOD) % MOD;
    }

    // Perform modular exponentiation (n^x % MOD)
    int mod_exp(int n, int x, int MOD) {
        int result = 1;
        while (x > 0) {
            if (x & 1) result = (result * n) % MOD;
            n = (n * n) % MOD;
            x >>= 1;
        }
        return result;
    }

    // Check if a number is a perfect square
    bool check_perfect_square(int n) {
        int t = sqrt(n);
        return t * t == n;
    }

    // Generate an array of minimum prime divisors for all numbers from 1 to n
    vector<int> get_array_min_prime_divisor(int n) {
        vector<int> min_prime(n + 1);
        iota(min_prime.begin(), min_prime.end(), 0);

        for (int i = 2; i * i <= n; ++i) {
            if (min_prime[i] == i) {
                for (int j = i * i; j <= n; j += i) {
                    if (min_prime[j] == j) min_prime[j] = i;
                }
            }
        }
        return min_prime;
    }

    // Generate an array of modular inverses for the elements of array `a`
    // assuming MOD is a prime number (using Fermat's Little Theorem)
    vector<int> get_array_inverse(vector<int> a, int MOD) {
        int n = a.size() - 1;
        vector<int> ans(n + 1), suffix_mul(n + 1);

        int mul_product = 1, prefix_mul = 1;

        for (int i = n; i >= 1; --i) {
            a[i] %= MOD;
            suffix_mul[i] = (i == n) ? a[i] : (suffix_mul[i + 1] * a[i]) % MOD;
            mul_product = (mul_product * a[i]) % MOD;
        }

        mul_product = mod_exp(mul_product, MOD - 2, MOD);

        for (int i = 1; i <= n; ++i) {
            ans[i] = (prefix_mul * (i == n ? 1 : suffix_mul[i + 1]) % MOD) * mul_product % MOD;
            prefix_mul = (prefix_mul * a[i]) % MOD;
        }

        return ans;
    }
};

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
};

void solve() {
    int q;
    cin >> q;

    Combinatorics combinatorics(1000000, MOD);

    while (q--) {
        int n, k;
        cin >> n >> k;
        cout << combinatorics.get_nCk(n, k) << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
