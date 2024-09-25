#include <bits/stdc++.h>
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve()
{
    int k, n;
    cin >> n >> k;
    string str;
    cin >> str;
    int cnt = 0;
    vector<int> s(n);
    for (int i = 0; i < n; i++)
    {
        s[i] = str[i] - '0';
    }
    int l = 0, r = n - 1;

    while (l < r)
    {
        if (s[l] != s[r])
            cnt++;
        l++;
        r--;
    }
    if (cnt > k)
    {
        cout << -1;
        return;
    }
    vector<bool> vst(n, false);
    l = 0, r = s.size() - 1;
    while (l < r)
    {
        if (s[l] != s[r])
        {
            if (s[l] > s[r])
                s[r] = s[l];
            else
                s[l] = s[r];
            k--;
            vst[l] = vst[r] = true;
        }
        l++;
        r--;
    }
    l = 0, r = n - 1;
    while (l < r)
    {
        if (k <= 0)
            break;
        if (s[l] == 9)
        {
            l++;
            r--;
            continue;
        }
        if (vst[l] == true)
        {
            if (k > 0)
            {
                s[l] = s[r] = 9;
                k--;
            }
        }
        else
        {
            if (k > 2)
            {
                s[l] = s[r] = 9;
                k -= 2;
            }
        }
        l++;
        r--;
    }
    if (k > 0 && n % 2 == 1)
    {
        int mid = n / 2;
        s[mid] = 9;
    }
    for (int i = 0; i < n; i++)
    {
        cout << s[i];
    }
    // cout << s;
}
int32_t main()
{
    solve();
}