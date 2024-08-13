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
    string s;
    cin >> s;
    int k;
    cin >> k;
    int l, r, ans = 0;
    l = r = 0;
    vector<int> check(30, 0);
    check[s[0] - 'a']++;
    while (r < s.size())
    {
        bool ok = true;
        for (int i = 0; i < 30; i++)
        {
            if (check[i] > k)
            {
                ok = false;
            }
        }
        if (ok)
        {
            ans += r - l + 1;
        }
        if (ok && r < (int)s.size())
        {
            r++;
            if (r < (int)s.size())
            {
                check[s[r] - 'a']++;
            }
        }
        else
        {
            check[s[l] - 'a']--;
            l++;
        }
        // cout << ans << " " << l << " " << r << "\n";
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