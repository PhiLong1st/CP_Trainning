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
        st[id] = max(st[id * 2], st[id * 2 + 1]);
    }
    int getMaxx(int id, int l, int r, int u, int v)
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
        int s1 = getMaxx(id * 2, l, mid, u, v);
        int s2 = getMaxx(id * 2 + 1, mid + 1, r, u, v);
        return max(s1, s2);
    }
};
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    Segment_Tree tree(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        a[i] /= a[i + 1];
        tree.update(1, 1, n, i, a[i]);
    }
    int ans = 0;
    for (int i = k + 1; i <= n; i++)
    {
        // cout << a[i] << " ";
        int minn = tree.getMaxx(1, 1, n, i - k, i - 1);
        ans += (minn <= 1);
    }
    cout << ans << "\n";
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