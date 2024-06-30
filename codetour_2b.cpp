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
    vector<int> dem(200);
    set<char> checkUnit;
    for (int i = 0; i < s.size(); i++)
    {
        dem[s[i] - 'a']++;
        checkUnit.insert(s[i]);
    }
    if (checkUnit.size() == 2)
    {
        for (int i = 0; i < 30; i++)
        {
            if (dem[i] == 1)
            {
                for (int j = 0; j < 30; j++)
                {
                    for (int u = 0; u < dem[j]; u++)
                    {
                        cout << (char)(j + 'a');
                    }
                }
                return;
            }
        }
    }
    stack<char> save;
    string pre = "", suf = "";
    for (int i = 0; i < 30; i++)
    {
        while (dem[i] >= 2)
        {
            pre += (char)(i + 'a');
            save.push((char)(i + 'a'));
            dem[i] -= 2;
        }
    }
    while (!save.empty())
    {
        suf += save.top();
        save.pop();
    }
    vector<char> savePre, saveSuf;
    int check = 0;
    for (int i = 0; i < 30; i++)
    {
        if (dem[i] > 0)
        {
            int l = pre[0] - 'a';
            int r = pre[0] - 'a';
            if (i == l)
            {
                check = 1;
            }
            if (i <= l)
            {
                savePre.push_back((char)(i + 'a'));
            }
            else
            {
                saveSuf.push_back((char)(i + 'a'));
            }
        }
    }
    if (saveSuf.empty())
    {
        if (savePre.size() != 0)
        {
            for (int i = 0; i < savePre.size() - 1; i++)
            {
                cout << savePre[i];
            }
            cout << pre << savePre[savePre.size() - 1] << suf;
        }
    }
    else
    {
        for (int i = 0; i < savePre.size(); i++)
        {
            cout << savePre[i];
        }
        cout << pre << saveSuf[0] << suf;
        for (int i = 1; i < saveSuf.size(); i++)
        {
            cout << saveSuf[i];
        }
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