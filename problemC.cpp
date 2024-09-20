/*
    Code by: KoKoDuDu
    Created: 19.09.2024 21:44:58
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

struct SparseTable
{

    const int LGMAX = 20;
    vector<vector<int>> spt;
    vector<int> arr;

    SparseTable(vector<int> arr)
    {
        this->arr = arr;
        spt.assign(LGMAX, vector<int>(arr.size()));
    }

    void prepare()
    {
        for (int i = 0; i < arr.size(); i++)
        {
            spt[0][i] = arr[i];
        }
        for (int bit = 1; bit < LGMAX; bit++)
        {
            for (int i = 0; i < arr.size(); i++)
            {
                spt[bit][i] = __gcd(spt[bit - 1][i], spt[bit - 1][i + (1 << (bit - 1))]);
            }
        }
    }
    int get_gcd(int l, int r)
    {
        int lg = log2(r - l + 1);
        return __gcd(spt[lg][l], spt[lg][r - (1 << lg)]);
    }
};


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    SparseTable f(a);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int l = i, r = n - 1, m1 = i, m2 = i;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (f.get_gcd(i, mid) <= a[i]) {
                r = mid - 1;
                m1 = mid;
            }
            else {
                l = mid + 1;
            }
        }
        l = i, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (f.get_gcd(i, mid) < a[i]) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
                m2 = mid;
            }
        }
        // res += m2 - m1 + 1;
        mp[a[i]] += m2 - m1 + 1;
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << mp[x] << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    // cin >> numTest;
    while (numTest--) {
        solve();
    }
    return 0;
}