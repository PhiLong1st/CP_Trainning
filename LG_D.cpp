

/*
    Code by: KoKoDuDu
    Created: 12.10.2024 08:37:01
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
const int N = 1e6 + 7;
vector<int> inv(N), fact(N), inv_fact(N);
void prepare() {
    inv[1] = 1;
    for (int i = 2; i < N; ++i) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        inv_fact[i] = inv_fact[i - 1] * inv[i] % MOD;
    }
}
int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
        cnt += (s[i] == '1');
    }
    if (k == 1) {
        cout << 1 << "\n";
        return;
    }
    if (cnt % k == 0) {
        if (cnt == 0) {
            cout << C(n - 1, k - 1) << "\n";
            return;
        }
        vector<int> save;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                save.push_back(i);
            }
        }
        int ans = 1;
        int val = cnt / k;
        for (int i = val; i < (int)save.size(); i += val) {
            if (i == 0) {
            }
            else {
                ans *= (save[i] - save[i - 1]);
            }
            ans %= MOD;
            // cout << i << " ";
        }
        cout << ans;
        cout << "\n";
    }
    else {
        cout << "0\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    prepare();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}