
/*
    Code by: KoKoDuDu
    Created: 29.12.2024 19:07:30
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
        int s1 = getSum(id * 2, l, mid, u, v);
        int s2 = getSum(id * 2 + 1, mid + 1, r, u, v);
        return (s1 + s2) % MOD;
    }
    int getMin(int id, int l, int r, int u, int v)
    {
        if (l > v || r < u)
        {
            return MOD;
        }
        if (u <= l && r <= v)
        {
            return st[id];
        }
        int mid = (l + r) >> 1;
        int s1 = getMin(id * 2, l, mid, u, v);
        int s2 = getMin(id * 2 + 1, mid + 1, r, u, v);
        return min(s1, s2);
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    int cnt_1 = 0;
    Segment_Tree tree(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt_1 += (a[i] == 1);
        tree.update(1, 1, n, i, a[i]);
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x == 1) {
            int l = 1, r = n;
            int ans = -1, isOk = false;
            if (y == 1) {
                if (cnt_1 > 0) cout << "YES\n";
                else cout << "NO\n";
                continue;
            }
            while (l <= r) {
                int mid = (l + r) / 2;
                int val = tree.getSum(1, 1, n, 1, mid);
                if (val >= y) {
                    if (val == y) {
                        isOk = true;
                    }
                    r = mid - 1;
                    ans = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            if (ans == -1) {
                cout << "NO\n";
            }
            else {
                if (isOk) {
                    cout << "YES\n";
                }
                else {
                    bool ok = false;
                    for (int i = ans; i <= n; ++i) {
                        if (a[i] != a[i - ans + 1]) {
                            ok = true;
                            break;
                        }
                    }
                    for (int i = ans + 1; i <= n; ++i) {
                        if (a[i] != a[i - ans]) {
                            ok = true;
                            break;
                        }
                    }
                    if (ok) cout << "YES\n";
                    else cout << "NO\n";
                }
            }
        }
        else {
            int z;
            cin >> z;
            tree.update(1, 1, n, y, z);
            if (z == 1 && a[y] == 2) {
                cnt_1++;
            }
            if (z == 2 && a[y] == 1) {
                cnt_1--;
            }
            a[y] = z;
        }
    }
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