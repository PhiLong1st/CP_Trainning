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
    vector<int> a(n + 1), save[1000];
    int ans = 0, dem = 0;
    map<int, int> check;
    priority_queue<int, vector<int>> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (check[a[i]] == 0)
        {
            dem++;
            check[a[i]] = dem;
            q.push(a[i]);
        }
        save[check[a[i]]].push_back(i);
        // cout << a[i] << " ";
    }
    vector<pll> res;
    while (!q.empty())
    {
        if (q.size() == 1)
        {
            break;
        }
        int x = q.top();
        q.pop();
        int y = q.top();
        if (y == 1)
        {
            cout << -1 << "\n";
            return;
        }
        int val = save[check[x]].size();
        for (int i = 1; i <= val; i++)
        {
            ans++;
            res.push_back(make_pair(save[check[x]].back(), save[check[y]].back()));
            int newVal = (x + y - 1) / y;
            if (check[newVal] == 0)
            {
                dem++;
                check[newVal] = dem;
                q.push(newVal);
            }
            save[check[newVal]].push_back(save[check[x]].back());
            save[check[x]].pop_back();
        }
        // cout << x << " " << y << " ";
        // cout << "\n";
    }
    cout << ans << "\n";
    for (auto i : res)
    {
        cout << i.first << " " << i.second << "\n";
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