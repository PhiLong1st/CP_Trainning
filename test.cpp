#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 1e6 + 123;
long long phi[mx];
long long r[mx];

int main()
{
    optimize();
    int lim = 1e6, i, j;
    for (i = 1;i <= lim;i++) phi[i] = i;
    for (i = 2;i <= lim;i++)
    {
        if (phi[i] == i)
        {
            for (j = i;j <= lim;j += i)
            {
                phi[j] /= i;
                phi[j] *= (i - 1);
            }
        }
    }

    for (i = 1;i <= lim;i++)
    {
        for (j = i;j <= lim;j += i)
        {
            r[j] += phi[i] * i;
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long ans = r[n] + 1;
        ans *= n;
        ans /= 2;

        cout << ans << endl;
    }
    return 0;
}