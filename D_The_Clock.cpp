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

int32_t main()
{
    int t, a, b, x, c, m, h;
    char d;
    for (std::cin >> t; t--; std::cout << c << d)
    {
        c = 0;
        std::cin >> a >> d >> b >> x;
        h = a;
        m = b;
        d = 10;
        do
        {
            m += x;
            h += m / 60;
            m %= 60;
            h %= 24;
            c += h / d == m % d & m / d == h % d;
        } while (h - a | m - b);
    }
}
