
/*
  Code by: linvg
  Created: 11.10.2024 22:37:07
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

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;
vector<int> sum;
struct info
{
    int first, second;
};
info operator+(info a, info b) {
    info best;
    if (a.first >= b.first) {
        best.second = a.second;
    }
    else {
        best.second = b.second;
    }
    best.first = max(a.first, b.first);
    return best;
}
struct Segment_Tree
{
    vector<info> st;
    int n;
    Segment_Tree()
    {
    }
    Segment_Tree(int n)
    {
        this->n = n;
        st.assign(4 * n + 37, { 0,0 });
    }
    void update(int id, int l, int r, int pos, int val)
    {
        int mid = (l + r) >> 1;
        if (l == r)
        {
            st[id].first = val;
            st[id].second = sum[pos - 1];
            return;
        }
        if (pos <= mid)
        {
            update(id * 2, l, mid, pos, val);
        }
        else
        {
            update(id * 2 + 1, mid + 1, r, pos, val);
        }
        st[id] = st[id * 2] + st[id * 2 + 1];
    }
    info getMaxx(int id, int l, int r, int u, int v)
    {
        if (l > v || r < u)
        {
            return { 0, 0 };
        }
        if (u <= l && r <= v)
        {
            return st[id];
        }
        int mid = (l + r) >> 1;
        info s1 = getMaxx(id * 2, l, mid, u, v);
        info s2 = getMaxx(id * 2 + 1, mid + 1, r, u, v);
        return s1 + s2;
    }
};
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sum.resize(n + 1, 0);
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i - 1];
    }
    dp[0][0] = 0;
    vector<Segment_Tree> save_tree(k + 2, Segment_Tree(n + 2));
    save_tree[0].update(1, 1, n + 1, 1, 0);
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = max(dp[i][0], dp[i - 1][0] + a[i - 1]);
        save_tree[0].update(1, 1, n + 1, i + 1, dp[i][0]);
        for (int l = 1; l <= k; ++l) {
            // for (int j = i; j >= 1; --j) {
            //     dp[i][l] = max(dp[i][l], dp[j - 1][l - 1] + sum[j - 1]);
            // }
            info val = save_tree[l - 1].getMaxx(1, 1, n + 1, 1, i);
            dp[i][l] = val.first + val.second - sum[i];
            dp[i][l] = max(dp[i][l], dp[i - 1][l] + a[i - 1]);
            save_tree[l].update(1, 1, n + 1, i + 1, dp[i][l]);
        }
    }
    int ans = -INF;
    for (int i = 0; i <= k; ++i) {
        // ans = max(ans, *max_element(all(dp[i])));
        ans = max(ans, save_tree[i].getMaxx(1, 1, n + 1, 1, n + 1).first);
        // cout << save_tree[i].getMaxx2(1, 1, n + 1, 1, n + 1) << " ";
    }
    cout << ans << '\n';
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}