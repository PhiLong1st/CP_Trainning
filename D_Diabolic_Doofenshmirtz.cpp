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
    int t = 1;
    function<bool(int val)> ask = [&](int val)
    {
        cout << "? " << val << "\n";
        cout.flush();
        int x;
        cin >> x;
        if (x == val)
        {
            return true;
        }
        if (x == 0)
        {
            cout << "! " << val << "\n";
            cout.flush();
        }
        else
        {
            cout << "! " << val - x << "\n";
            cout.flush();
        }
        return false;
    };
    while (ask(t))
    {
        t *= 2;
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