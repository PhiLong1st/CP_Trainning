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
    vector<int> a(n + 1), tmp;
    vector<vector<int>> save(n + 1, vector<int>());
    map<int, int> check;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tmp.push_back(a[i]);
    }
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for (int i = 1; i <= n; i++)
    {
        int val = lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
        check[val] = a[i];
        a[i] = val;
        save[val].push_back(i);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << "\n";
    int ans = 0;
    tuple<int, int, int> res;
    for (int val = 0; val <= n; val++)
    {
        if (save[val].size() == 0)
        {
            continue;
        }
        int minn = 0;
        for (int i = 0; i < save[val].size(); i++)
        {
            if (2LL * minn - save[val][minn] > 2LL * i - save[val][i])
            {
                minn = i;
            }
            if (ans < 2LL * i - save[val][i] - (2LL * minn - save[val][minn]) + 1)
            {
                ans = max(ans, 2LL * i - save[val][i] - (2LL * minn - save[val][minn]) + 1);
                res = make_tuple(check[val], save[val][minn], save[val][i]);
            }
        }
    }
    // cout << ans << " " << get<0>(res) << " " << get<1>(res) << " " << get<2>(res) << "\n";
    cout << get<0>(res) << " " << get<1>(res) << " " << get<2>(res) << "\n";
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