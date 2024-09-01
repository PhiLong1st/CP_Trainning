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
    int n, m;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    vector<string> s(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    for (int j = 1; j <= m; j++)
    {
        string str = s[j];
        if (str.size() != n + 1)
        {
            cout << "NO\n";
            continue;
        }
        vector<int> tmp(n + 1);
        map<char, int> saveStr;
        for (int i = 1; i < str.size(); i++)
        {
            if (saveStr[str[i]] == 0)
            {
                saveStr[str[i]] = a[i];
            }
            tmp[i] = saveStr[str[i]];
        }
        vector<char> tmpNum(n + 1);
        map<int, char> saveNum;
        for (int i = 1; i < str.size(); i++)
        {
            if (saveNum[a[i]] == 0)
            {
                saveNum[a[i]] = str[i];
            }
            tmpNum[i] = saveNum[a[i]];
        }
        bool ok = (tmp == a);
        for (int i = 1; i < str.size(); i++)
        {
            if (str[i] != tmpNum[i])
            {
                ok = false;
            }
        }
        if (ok)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
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