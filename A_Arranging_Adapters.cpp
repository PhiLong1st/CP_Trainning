/*
  Code by: linvg
  Created: 03.12.2024 19:00:48
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
    int n, s;
    cin >> n >> s;
    vector<int> a(n), sum_save(n), cnt_1(n), cnt_2(n);
    for (auto& c : a) cin >> c;
    if (min(n, s) == 1) {
        cout << 1;
        return;
    }
    sort(all(a));
    int res = 0;
    int sum = 0, mock = 0;
    // for (int x : a) {
    //     cerr << x << ' ';
    // }
    for (int i = 0; i < sz(a); ++i) {
        sum += a[i] - a[i] % 3;
        if (i == 0) {
            sum_save[i] = a[i] - a[i] % 3;
            cnt_1[i] = (a[i] % 3 == 1);
            cnt_2[i] = (a[i] % 3 == 2);
        }
        else {
            sum_save[i] = sum_save[i - 1] + a[i] - a[i] % 3;
            cnt_1[i] = cnt_1[i - 1] + (a[i] % 3 == 1);
            cnt_2[i] = cnt_2[i - 1] + (a[i] % 3 == 2);
        }
        if (i > 1) {
            int val = sum_save[i - 2] / 3, bonus = 0;
            if (cnt_1[i - 2] <= cnt_2[i - 2]) {
                bonus = cnt_1[i - 2] + ((cnt_2[i - 2] - cnt_1[i - 2]) / 2) * 2 + ((cnt_2[i - 2] - cnt_1[i - 2]) % 2);
            }
            else {
                bonus = cnt_2[i - 2] + ((cnt_1[i - 2] - cnt_2[i - 2]) / 2) + ((cnt_1[i - 2] - cnt_2[i - 2]) % 2);
            }
            // cout << i << ' ' << cnt_1[i - 2] << ' ' << cnt_2[i - 2] << ' ' << sum_save[i - 2] << ' ' << val << ' ' << bonus << '\n';
            if (val + bonus + 2 > s) {
                // cout << val << ' ' << s << " " << bonus << " A ";
                break;
            }
        }
        mock = i + 1;
    }
    cout << res + mock << '\n';
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}