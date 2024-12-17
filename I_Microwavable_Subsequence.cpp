
/*
    Code by: KoKoDuDu
    Created: 17.12.2024 09:58:40
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int N = 3e5 + 7;

int fw[N];

void add(int i, int x) {
    for (; i < N; i += i & -i) {
        fw[i] += x;
    }
}

int get(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i) {
        res += fw[i];
    }
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    unordered_map<int, bool> pos;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]] = 1;
    }
    unordered_map<int, int> last;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (last.count(a[i]) == 0) {
            res += get(i + 1);
            last[a[i]] = i + 1;
            add(last[a[i]], 1);
            continue;
        }
        res += get(n) - get(last[a[i]]);
        if (last.count(a[i]) != 0) add(last[a[i]], -1);
        last[a[i]] = i + 1;
        add(last[a[i]], 1);
    }
    res += 1ll * sz(last) * (sz(last) - 1) / 2;
    res += sz(pos) * (m - sz(pos));
    cout << res << '\n';

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}