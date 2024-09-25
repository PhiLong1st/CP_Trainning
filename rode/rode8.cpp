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
    vector<vector<int>> save(30, vector<int>());
    for (int i = 0; i < s.size(); i++)
    {
        int g = s[i] - 'a';
        save[g].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (save[i].size() == 0 || save[j].size() == 0)
            {
                continue;
            }
            vector<int> tmp(save[i].size() + save[j].size());
            bool ok = true;
            merge(save[i].begin(), save[i].end(), save[j].begin(), save[j].end(), tmp.begin());
            // cout << i << " " << j << "aaa\n";
            for (int u = 1; u < tmp.size(); u++)
            {
                if (s[tmp[u]] == s[tmp[u - 1]])
                {
                    ok = false;
                    break;
                }
                // cout << tmp[u] << " ";
            }
            // cout << "\n";
            if (ok)
            {
                ans = max(ans, (int)tmp.size());
            }
            // for (auto c : tmp)
            //     cerr << c << ' ';
            // cerr << '\n';
        }
        // cerr << i << "aaa" << "\n ";
        // for (auto c : save[i])
        //     cerr
        //         << c << ' ';
        // cerr << '\n';
    }
    cout << ans;
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