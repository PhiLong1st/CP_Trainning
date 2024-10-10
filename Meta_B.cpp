/*
    Code by: KoKoDuDu
    Created: 06.10.2024 00:20:48
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 7;
bitset<N> is_prime;
// is_prime[i] = 1: prime
void sieve() {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i < N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    sieve();
    vector<int> ans(N);
    ans[5] = 2;
    for (int i = 6; i < N; ++i) {
        ans[i] += ans[i - 1] + (is_prime[i] && is_prime[i - 2]);
    }
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        int n;
        cin >> n;
        cout << ans[n] << "\n";
    }
    return 0;
}