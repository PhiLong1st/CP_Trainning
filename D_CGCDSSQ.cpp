/*
    Code by: KoKoDuDu
    Created: 21.09.2024 02:18:27
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (T& x : v) is >> x; return is; }
const int MOD = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    cin >> q;
    unordered_map<int, int> ans, divisors, nextDivisors;
    for (int x : a) {
        nextDivisors.clear();
        for (auto div : divisors) {
            nextDivisors[__gcd(div.first, x)] += div.second;
        }
        nextDivisors[x]++;
        swap(nextDivisors, divisors);
        for (auto div : divisors) {
            ans[div.first] += div.second;
        }
    }
    while (q--)
    {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }
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