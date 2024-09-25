#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll u, v;
ll a[100], n;
ll b[20][2][100][1500];
ll f[10000];
ll sinh(ll i, bool kt, ll t, ll val)
{
    bool check;
    if (i > n)
    {
        // cout<<t<<" ";
        return f[t] && f[val];
    }
    if (b[i][kt][t][val] != -1)
    {
        // cout<<"A";
        //     cout<<i<<" "<<kt<<" "<<t;
        return b[i][kt][t][val];
    }
    ll maxc;
    ll kq = 0;
    if (kt)
    {
        maxc = 9;
    }
    else
    {
        maxc = a[i];
    }
    for (ll j = 0; j <= maxc; j++)
    {
        check = kt || (j < maxc);
        kq += sinh(i + 1, check, t + j, val + j * j);
    }
    b[i][kt][t][val] = kq;
    return kq;
}
ll g(ll x)
{
    memset(b, -1, sizeof(b));
    n = 0;
    while (x)
    {
        n++;
        a[n] = x % 10;
        x /= 10;
    }
    reverse(a + 1, a + n + 1);
    return sinh(1, false, 0, 0);
}
int main()
{
    int n;
    cin >> n;
    for (ll i = 1; i <= 1500; i++)
    {
        f[i] = 1;
    }
    f[1] = f[0] = 0;
    for (ll i = 2; i <= 1500; i++)
        if (f[i] == 1)
            for (ll j = i * 2; j <= 1500; j += i)
            {
                f[j] = 0;
            }
    while (n--)
    {

        cin >> u >> v;
        // g(v);
        cout << g(v) - g(u - 1) << "\n";
    }
}
// 1 110
