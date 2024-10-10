
/*
    Code by: KoKoDuDu
    Created: 27.09.2024 19:48:56
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
            st[id] += val;
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
    vector<int> color(n + 1), ans(n + 1);
    vector<vector<int>> adj(n + 1, vector<int>());
    vector<pll> edge(n + 1);
    Segment_Tree tree(n);
    for (int i = 1; i <= n; ++i) {
        cin >> color[i];
        tree.update(1, 1, n, color[i], 1);
    }
    for (int i = 1; i <= n - 1; ++i) {
        cin >> edge[i].first >> edge[i].second;
        adj[edge[i].first].push_back(edge[i].second);
        adj[edge[i].second].push_back(edge[i].first);
    }
    function< void(int, int)>dfs;
    dfs = [&](int par, int x) {
        for (int g : adj[x]) {
            if (g != par) {
                dfs(x, g);
            }
        }
        for (int g : adj[x]) {
            if (g != par) {
                ans[color[x]] += tree.getSum(1, 1, n, color[g], color[g]);
                tree.update(1, 1, n, color[x], -1);
            }
        }
        };
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    while (numTest--) {
        solve();
    }
    return 0;
}