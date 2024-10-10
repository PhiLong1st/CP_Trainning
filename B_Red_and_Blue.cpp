
/*
    Code by: KoKoDuDu
    Created: 30.09.2024 14:14:03
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

int kadane(vector<int> a) {
    int ans = 0, sum = 0;
    for (int i = 0; i < a.size(); ++i) {
        sum += a[i];
        ans = max(ans, sum);
    }
    return ans;
}
void solve() {
    int n, m, ans1 = 0, ans2 = 0, sum1 = 0, sum2 = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        sum1 += a;
        ans1 = max(ans1, sum1);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        sum2 += a;
        ans2 = max(ans2, sum2);
    }
    cout << ans1 + ans2 << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    cin >> numTest;
    while (numTest--) {
        solve();
    }
    return 0;
}