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
    string s;
    cin >> n;
    int sz = (1 << n);
    vector<int> a(sz + 1), save(n + 1);
    for (int i = 1; i <= sz; i++)
    {
        cin >> a[i];
    }
    cin >> s;
    int res = n;
    int dem = n;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            res++;
        }
        else
        {
            res--;
            if (res < dem)
            {
                for (int u = 1; u <= sz / 2; u++)
                {
                    a[u] += a[u + sz / 2];
                }
                sz /= 2;
            }
        }
        dem = min(dem, res);
    }
    for (int i = 1; i <= (1 << res) - sz; i++)
    {
        cout << 0 << " ";
    }
    for (int i = 1; i <= sz; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
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