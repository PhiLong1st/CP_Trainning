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
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && a[st.top()] % a[i] == 0)
        {
            st.pop();
        }
        if (!st.empty())
        {
            l[i] = st.top() + 1;
        }
        else
        {
            l[i] = 1;
        }
        st.push(i);
    }
    while (!st.empty())
    {
        st.pop();
    }
    for (int i = n; i >= 1; i--)
    {
        while (!st.empty() && a[st.top()] % a[i] == 0)
        {
            st.pop();
        }
        if (!st.empty())
        {
            r[i] = st.top() - 1;
        }
        else
        {
            r[i] = n;
        }
        st.push(i);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << l[i] << " ";
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << r[i] << " ";
    // }
    int ans = 0, res = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, r[i] - l[i]);
    }
    // vector<int> save;
    set<pll> save;
    for (int i = 1; i <= n; i++)
    {
        if (r[i] - l[i] == ans)
        {
            // cout << i << " ";
            // save.push_back(l[i]);
            save.insert({l[i], r[i] - l[i]});
        }
    }
    // sort(save.begin(), save.end());
    cout << save.size() << " " << ans << "\n";
    for (auto i : save)
    {
        cout << i.first << " ";
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