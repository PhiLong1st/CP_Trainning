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
    int ans;
    pll pre, suf;
    int preVal, sufVal;
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
    info updateInfo(info a, info b)
    {
        info tmp;
        tmp.pre = a.pre;
        tmp.preVal = a.preVal;
        tmp.suf = b.suf;
        tmp.sufVal = b.sufVal;
        if (a.sufVal != b.preVal)
        {
            tmp.ans = a.ans + b.ans;
            return tmp;
        }
        // a.sufVal == b.preVal
        tmp.ans = a.ans + b.ans - cal(a.suf.first, a.suf.second) - cal(b.pre.first, b.pre.second) + cal(a.suf.first, b.pre.second);
        if (a.preVal == a.sufVal)
        {
            tmp.pre.second = b.pre.second;
        }
        if (b.sufVal == b.preVal)
        {
            tmp.suf.first = a.suf.first;
        }
        return tmp;
    }
    int cal(int l, int r)
    {
        return (n - l + 1) * r - (r - l + 1) * (r - l) / 2;
    }
    void update(int id, int l, int r, int pos, int val)
    {
        int mid = (l + r) >> 1;
        if (l == r)
        {
            st[id].preVal = st[id].sufVal = val;
            st[id].pre.first = st[id].suf.first = st[id].pre.second = st[id].suf.second = pos;
            st[id].ans = cal(pos, pos);
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
        // st[id] = st[id * 2] + st[id * 2 + 1];
        st[id] = updateInfo(st[id * 2], st[id * 2 + 1]);
    }
    void showId(int id)
    {
        cout << st[id].ans << "\n";
        cout << st[id].preVal << " " << st[id].pre.first << " " << st[id].pre.second << "\n";
        cout << st[id].sufVal << " " << st[id].suf.first << " " << st[id].suf.second << "\n";
        cout << "-----------------\n";
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    // vector<int> a(n + 1);
    Segment_Tree tree(n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        tree.update(1, 1, n, i, x);
    }
    // tree.update(1, 1, n, 3, 2);
    // tree.update(1, 1, n, 4, 2);
    // cout << tree.cal(2, 3) << " " << tree.cal(4, 4) << " " << tree.cal(2, 4) << "\n";
    // for (int i = 1; i <= 4 * n; i++)
    // {
    //     cout << i << "-----\n";
    //     tree.showId(i);
    // }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        tree.update(1, 1, n, x, y);
        cout << tree.st[1].ans << "\n";
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