
/*
    Code by: KoKoDuDu
    Created: 06.12.2024 16:38:34
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

struct Segment_Tree
{
    vector<int> st;
    int n;
    Segment_Tree()
    {
    }
    Segment_Tree(int n)
    {
        this->n = n;
        st.assign(4 * n + 37, 0);
    }
    void update(int id, int l, int r, int pos, int val)
    {
        int mid = (l + r) >> 1;
        if (l == r)
        {
            st[id] = val;
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
        st[id] = __gcd(st[id * 2], st[id * 2 + 1]);
    }
    int get_gcd(int id, int l, int r, int u, int v)
    {
        if (l > v || r < u)
        {
            return 0;
        }
        if (u <= l && r <= v)
        {
            return st[id];
        }
        int mid = (l + r) >> 1;
        ;
        int s1 = get_gcd(id * 2, l, mid, u, v);
        int s2 = get_gcd(id * 2 + 1, mid + 1, r, u, v);
        return __gcd(s1, s2);
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    Segment_Tree tree(n);
    for (int i = 2; i <= n; ++i) {
        tree.update(1, 1, n - 1, i - 1, abs(a[i] - a[i - 1]));
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << 0 << ' ';
        }
        else {
            cout << tree.get_gcd(1, 1, n - 1, l, r - 1) << ' ';
        }
    }
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}