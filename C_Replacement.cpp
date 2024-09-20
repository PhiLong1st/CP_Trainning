/*
    Code by: KoKoDuDu
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define db double
#define pll pair<int, int>
#define pdb pair<db, db>
#define vector2d(name, sz1, sz2, type, val) vector<vector<type>> name(sz1, vector<type>(sz2, val))
#define vector3d(name, sz1, sz2, sz3, type, val) vector<vector<vector<type>>> name(sz1, vector<vector<type>>(sz2, vector<type>(sz3, val)))
#define vector4d(name, sz1, sz2, sz3, sz4, type, val) vector<vector<vector<vector<type>>>> name(sz1, vector<vector<vector<type>>>(sz2, vector<vector<type>>(sz3, vector<type>(sz4, val))))

const int MOD = 1e9 + 7;
const int INF = 1e18;
struct info
{
    int ans, l, r, posx, posy;
};
info operator+(info a, info b)
{
    info tmp;
    if (a.ans == -1)
    {
        return b;
    }
    if (b.ans == -1)
    {
        return a;
    }
    if (a.ans == -2)
    {
        b.l = 0;
        b.posx = a.posx;
        return b;
    }
    if (b.ans == -2)
    {
        a.posy = b.posy;
        a.r = 0;
        return a;
    }
    tmp.l = a.l;
    tmp.r = b.r;
    tmp.posx = a.posx;
    tmp.posy = b.posy;
    tmp.ans = a.ans + b.ans;
    if (a.posy - a.posx == a.ans)
    {
        tmp.l += b.l;
    }
    if (b.posy - b.posx == b.ans)
    {
        tmp.r += a.r;
    }
    if (a.r > 0 && b.l > 0)
    {
        tmp.ans++;
    }
    return tmp;
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
        st.assign(4 * n + 37, info());
    }
    void update(int id, int l, int r, int pos, int val)
    {
        int mid = (l + r) >> 1;
        if (l == r)
        {
            st[id].l = st[id].r = val;
            st[id].posx = st[id].posy = pos;
            st[id].ans = 0;
            if (val == 0)
            {
                st[id].ans = -2;
            }
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
    info getSum(int id, int l, int r, int u, int v)
    {
        if (l > v || r < u)
        {
            info tmp;
            tmp.ans = tmp.r = tmp.l = -1;
            return tmp;
        }
        if (u <= l && r <= v)
        {
            return st[id];
        }
        int mid = (l + r) >> 1;
        info s1 = getSum(id * 2, l, mid, u, v);
        info s2 = getSum(id * 2 + 1, mid + 1, r, u, v);
        return s1 + s2;
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;
    Segment_Tree tree(n);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '.')
        {
            tree.update(1, 1, n, i, 1);
        }
        else
        {
            tree.update(1, 1, n, i, 0);
        }
    }
    while (q--)
    {
        int pos;
        char t;
        cin >> pos >> t;
        if (t == '.')
        {
            tree.update(1, 1, n, pos, 1);
        }
        else
        {
            tree.update(1, 1, n, pos, 0);
        }
        cout << max(0LL, tree.getSum(1, 1, n, 1, n).ans) << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    while (numTest--)
    {
        solve();
    }
    return 0;
}