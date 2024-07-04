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
    int n = s.size();
    s = " " + s;
    string tmp = "";
    vector<int> save;
    for (int i = 1; i <= n; i++)
    {
        int res = 1;
        tmp += s[i];
        while (i < n && s[i] == s[i + 1])
        {
            res++;
            i++;
        }
        save.push_back(res);
    }
    int ans = 0;
    if (tmp.size() % 2 == 0 || (tmp.size() % 2 == 1 && (tmp[0] == 'B')))
    {
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] == 'A')
            {
                ans += save[i];
            }
        }
        cout << ans << "\n";
        return;
    }
    int check = 0;
    for (int i = 1; i < tmp.size(); i += 2)
    {
        if (save[i] > 1)
        {
            check = 1;
            break;
        }
    }
    if (check == 1)
    {
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] == 'A')
            {
                ans += save[i];
            }
        }
        cout << ans << "\n";
        return;
    }
    int minn = INF;
    for (int i = 0; i < save.size(); i++)
    {
        if (tmp[i] == 'A')
        {
            ans += save[i];
            minn = min(minn, save[i]);
        }
    }
    if (minn == INF)
        minn = 0;
    cout << ans - minn << "\n";
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