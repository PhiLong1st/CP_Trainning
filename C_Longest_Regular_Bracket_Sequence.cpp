/*
    Code by: KoKoDuDu
    Created: 19.09.2024 11:21:39
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
        build();
    }

    void build()
    {
        for (int i = 0; i < arr.size(); i++) {
            spt[0][i] = arr[i];
        }
        for (int bit = 1; bit < LGMAX; bit++)
        {
            for (int i = 0; i + (1 << (bit - 1)) < arr.size(); i++)
            {
                spt[bit][i] = min(spt[bit - 1][i], spt[bit - 1][i + (1 << (bit - 1))]);
            }
        }
    }
    int get_min(int l, int r) {
        if (l > r) {
            return INT_MAX;
        }
        int lg = 31 - __builtin_clz(r - l + 1);
        return min(spt[lg][l], spt[lg][r - (1 << lg) + 1]);
    }
};
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n + 1);
    unordered_map<int, vector<int>> pos;
    pos[n].push_back(0);
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + (s[i - 1] == '(') - (s[i - 1] == ')');
        pos[a[i] + n].push_back(i);
    }
    SparseTable tb(a);
    int best = 0;
    unordered_map<int, int>cnt;
    cnt[0]++;
    for (int i = 0; i <= n; i++) {
        int l = 0, r = n - i, ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (tb.get_min(i, i + mid) >= a[i]) {
                l = mid + 1;
                ans = mid;
            }
            else {
                r = mid - 1;
            }
        }
        int p = upper_bound(pos[a[i] + n].begin(), pos[a[i] + n].end(), i + ans) - pos[a[i] + n].begin() - 1;
        cnt[pos[a[i] + n][p] - i]++;
        best = max(best, pos[a[i] + n][p] - i);
    }
    if (best == 0) return void(cout << "0 1");
    cout << best << " " << cnt[best];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    while (numTest--) {
        solve();
    }
    return 0;
}