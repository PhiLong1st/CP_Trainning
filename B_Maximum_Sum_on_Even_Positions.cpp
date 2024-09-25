
/*
    Code by: KoKoDuDu
    Created: 25.09.2024 17:13:37
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), sumOdd(n + 1), sumEven(n + 1), dis(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sumOdd[i] = sumOdd[i - 1] + ((i % 2 == 0) ? a[i] : 0);
        sumEven[i] = sumEven[i - 1] + ((i % 2 != 0) ? a[i] : 0);
        dis[i] = sumOdd[i] - sumEven[i];
    }
    int posEven = 2, posOdd = 1, ans = sumEven[n];
    for (int i = 2; i <= n; ++i) {
        // for (int j = 1; j < i; ++j) 
        {
            if (i % 2 == 0) {
                int val = max(0LL, dis[i] - dis[posOdd - 1]);
                ans = max(ans, sumEven[n] + val);
                if (dis[posOdd - 1] > dis[i]) {
                    posOdd = i + 1;
                }
            }
            else {
                int val = max(0LL, dis[i] - dis[posEven - 1]);
                ans = max(ans, sumEven[n] + val);
                if (dis[posEven - 1] > dis[i]) {
                    posEven = i + 1;
                }
            }
            // if ((i - j + 1) % 2 == 0) {
            //     // cout << i << " " << j << ": ";
            //     int val = max(0LL, dis[i] - dis[j - 1]);
            //     ans = max(ans, sumEven[n] + val);
            //     // cout << sumArr << " " << maxx << "\n";
            // }
        }
    }
    cout << ans << "\n";
}
//if r even , l odd => sumodd[r] - sumodd[l] > sumeven[r] - sumeven[l]
//if r odd , l even => sumodd[r] - sumodd[l] < sumeven[r] - sumeven[l]
// dis[r] - dis[l]>0

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