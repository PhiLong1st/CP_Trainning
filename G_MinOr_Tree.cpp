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

struct edgeInfo
{
    int sta, end, val;
    edgeInfo(int u, int v, int w)
    {
        sta = u;
        end = v;
        val = w;
    }
};
struct DSU
{
    /*
    numEdge is the number of edges is joined
    */
    int n, numEdge;
    vector<int> par, num;
    DSU(int sz)
    {
        n = sz;
        numEdge = 0;
        par.assign(n + 1, 0);
        num.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
        }
    }
    int findPar(int x)
    {
        if (x == par[x])
        {
            return x;
        }
        return par[x] = findPar(par[x]);
    }
    bool join(int x, int y)
    {
        x = findPar(x);
        y = findPar(y);
        if (x == y)
        {
            return false;
        }
        if (num[x] < num[y])
        {
            num[y] += num[x];
            par[x] = y;
        }
        else
        {
            num[x] += num[y];
            par[y] = x;
        }
        numEdge++;
        return true;
    }
};

void solve()
{
    int numNode, numEdge;
    cin >> numNode >> numEdge;
    vector<int> isBan(numEdge + 1);
    vector<edgeInfo> edgeList;
    for (int i = 1; i <= numEdge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(edgeInfo(u, v, w));
    }
    for (int bit = 30; bit >= 0; bit--)
    {
        int mask = (1 << bit);
        bool ok = false;
        vector<int> st;
        for (int i = 0; i < edgeList.size(); i++)
        {
            if (isBan[i])
                continue;
            if ((mask & edgeList[i].val))
            {
                isBan[i] = 1;
                st.push_back(i);
            }
        }
        DSU dsu(numNode);
        for (int i = 0; i < edgeList.size(); i++)
        {
            if (isBan[i])
                continue;
            dsu.join(edgeList[i].sta, edgeList[i].end);
        }
        ok = (dsu.numEdge == numNode - 1);
        if (!ok)
        {
            for (auto c : st)
                isBan[c] = 0;
        }
    }
    int ans = 0;
    DSU dsu(numNode);
    for (int i = 0; i < edgeList.size(); i++)
    {
        if (isBan[i])
            continue;
        if (dsu.join(edgeList[i].sta, edgeList[i].end))
        {
            ans |= edgeList[i].val;
        }
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