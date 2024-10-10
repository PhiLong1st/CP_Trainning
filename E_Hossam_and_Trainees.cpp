
/*
    Code by: KoKoDuDu
    Created: 02.10.2024 18:24:55
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
const int sz = (int)sqrt(1000000000) + 1;
vector<int> primes;
void solve() {
    int n;
    cin >> n;
    vector<bool>check(sz + 1, false);
    map<int, int>cntPrime;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int cnt = 0;
    sort(a.begin() + 1, a.end());
    for (int i = 2; i <= n; ++i) {
        if (__gcd(a[i], a[i - 1]) != 1) {
            return void(cout << "YES\n");
        }
    }
    for (int i = 1; i <= n; ++i) {
        bool ok = true;
        if (a[i] == 1) continue;
        for (int num : primes) {

            if (a[i] % num == 0) {
                ok = false;
                if (check[num]) { return void(cout << "YES\n"); }
                check[num] = true;
            }
        }
        if (ok) {
            cntPrime[a[i]]++;
            if (cntPrime[a[i]] > 1) { return void(cout << "YES\n"); }
        }
    }
    cout << "NO\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    cin >> numTest;
    vector<bool>isPrime(sz + 1);
    for (int i = 2; i <= sz; ++i) {
        if (isPrime[i]) continue;
        for (int j = i * i; j <= sz; j += i) {
            isPrime[j] = 1;
        }
    }
    for (int i = 2; i <= sz; ++i) {
        if (isPrime[i]) continue;
        primes.push_back(i);
    }
    while (numTest--) {
        solve();
    }
    return 0;
}