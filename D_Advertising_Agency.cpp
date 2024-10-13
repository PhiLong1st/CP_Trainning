

/*
    Code by: KoKoDuDu
    Created: 13.10.2024 17:45:03
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
    vector<int> a(n + 1);
    map<int, int>cnt;
    vector<int> save;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
        if (cnt[a[i]] == 1) {
            save.push_back(a[i]);
        }
    }
    sort(save.begin(), save.end(), greater<int>());
    int ans = 1;
    for (int i = 0; i < (int)save.size(); ++i) {
        if (k < cnt[save[i]]) {
            ans = C(cnt[save[i]], k);
            break;
        }
        else {
            k -= cnt[save[i]];
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    prepare();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}