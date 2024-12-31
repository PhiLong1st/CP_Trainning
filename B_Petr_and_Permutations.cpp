
/*
    Code by: KoKoDuDu
    Created: 31.12.2024 15:51:23
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
        st[id] = st[id * 2] + st[id * 2 + 1];
    }
    int getSum(int id, int l, int r, int u, int v)
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
        int s1 = getSum(id * 2, l, mid, u, v);
        int s2 = getSum(id * 2 + 1, mid + 1, r, u, v);
        return s1 + s2;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    Segment_Tree tree(n);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += tree.getSum(1, 1, n, pos[i], n);
        tree.update(1, 1, n, pos[i], 1);
    }
    if (ans % 2 == n % 2) cout << "Petr\n";
    else cout << "Um_nik\n";
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