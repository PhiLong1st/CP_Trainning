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
    int val = 0, lazy = 0;
};
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
    void down(int id, int l, int r)
    {
        int t = st[id].lazy;
        st[id * 2].val += t;
        st[id * 2 + 1].val += t;
        st[id * 2].lazy += t;
        st[id * 2 + 1].lazy += t;
        st[id].lazy = 0;
    }
    void update(int id, int l, int r, int u, int v)
    {
        if (l > v || r < u)
        {
            return;
        }
        if (u <= l && r <= v)
        {
            st[id].val += r - l + 1;
            st[id].lazy += 1;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id * 2, l, mid, u, v);
        update(id * 2 + 1, mid + 1, r, u, v);
        st[id].val = st[id * 2].val + st[id * 2 + 1].val;
    }
    int getMaxx(int id, int l, int r, int u, int v)
    {
        if (l > v || r < u)
        {
            return 0;
        }
        if (u <= l && r <= v)
        {
            return st[id].val;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        int s1 = getMaxx(id * 2, l, mid, u, v);
        int s2 = getMaxx(id * 2 + 1, mid + 1, r, u, v);
        return s1 + s2;
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    Segment_Tree tree(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    function<int(int x, int num)> cal = [&](int x, int num)
        {
            for (int i = 1; i <= num; i++)
            {
                if (x < 10)
                {
                    break;
                }
                int res = 0;
                while (x > 0)
                {
                    res += x % 10;
                    x /= 10;
                }
                x = res;
            }
            return x;
        };
    for (int i = 1; i <= q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, y;
            cin >> x >> y;
            tree.update(1, 1, n, x, y);
        }
        else
        {
            int x;
            cin >> x;
            int num = tree.getMaxx(1, 1, n, x, x);
            cout << cal(a[x], num) << "\n";
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    cin >> numTest;
    while (numTest--)
    {
        solve();
    }
    return 0;
}