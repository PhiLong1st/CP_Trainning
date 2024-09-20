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
    vector<int> a(n + 1), cnt(n + 1), ans(n + 1), used(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == a[i])
        {
            continue;
        }
        if (cnt[a[i]] == 0){
            res++;
            ans[i] = a[i];
            used[a[i]] = 1;
        }
        cnt[a[i]]++;
    }
    vector<int> save;
    for (int i = 1; i <= n; i++)
    {
        if (used[i] == 0)
        {
            save.push_back(i);
        }
        // cout << ans[i] << " ";
    }
    if (save.size() == 1)
    {
        cout << res << "\n";
        for (int i = 1; i <= n; i++)
        {
            if (ans[i] == a[save[0]])
            {
                ans[save[0]] = a[save[0]];
                ans[i] = save[0];
                break;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << res << "\n";
        vector<int> vt;
        for (int i = 1; i <= n; i++)
        {
            if (ans[i] == 0)
            {
                vt.push_back(i);
            }
        }
        for (int i = 0; i < save.size(); i++)
        {
            ans[vt[i]] = save[i];
        }
        for (int i = 1; i < vt.size(); i++)
        {
            if (ans[vt[i]] == vt[i])
            {
                swap(ans[vt[i]], ans[vt[i - 1]]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
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