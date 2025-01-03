
/*
  Code by: linvg
  Created: 12.10.2024 00:58:13
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T gcd(initializer_list<T> __l) { int a = 0; for (auto x : __l) { a = gcd(a, x); } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }

// #define DBG

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#endif

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> B(n + 1), P(n + 1), F(n + 1);
    for (int i = 1; i <= n; ++i) cin >> B[i];
    for (int i = 1; i <= n; ++i) cin >> P[i];
    for (int i = 1; i <= n; ++i) cin >> F[i];
    int w = 480, s = 300;
    vector<int> dp(w + s + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = w + s; j >= 1; --j) {
            if (j >= 3 * B[i]) {
                dp[j] = max(dp[j], dp[j - 3 * B[i]] + P[i]);
            }
        }
    }
    int pleasure = *max_element(all(dp));
    dp.assign(w + s + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = w + s; j >= 1; --j) {
            if (j >= 3 * B[i]) {
                dp[j] = max(dp[j], dp[j - 3 * B[i]] + F[i]);
            }
        }
    }
    int fame = *max_element(all(dp));
    cout << (pleasure == fame ? "EITHER" : (pleasure > fame ? "PLEASURE" : "FAME")) << '\n';
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}