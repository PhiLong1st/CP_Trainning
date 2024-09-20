/*
    Code by: KoKoDuDu
    Created: 20.09.2024 23:08:25
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = 1e12;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int bonus = 0;
        bool isOk = true;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] < mid) {
                bonus += mid - a[i];
            }
            else {
                bonus -= a[i] - mid;
            }
            if (bonus < 0) {
                isOk = false;
                break;
            }
        }
        if (isOk) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    int ans = l;
    l = 0, r = ans;
    int ans2 = 0, res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        int sum = 0;
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > ans) {
                sum += a[i] - ans;
            }
            else if (a[i] < mid) {
                if (sum < mid - a[i]) {
                    ok = false;
                    break;
                }
                sum -= mid - a[i];
            }
        }
        if (ok) {
            l = mid + 1;
            ans2 = mid;
            res = sum;
        }
        else {
            r = mid - 1;
        }
    }
    int maxi = 0, minn = 0;
    int sum = 0;
    vector<int> save(n);
    for (int i = 0; i < n; i++)
    {
        // cout << a[i] << " ";
        if (a[i] > ans) {
            sum += a[i] - ans;
            a[i] = ans;
        }
        else if (a[i] < ans2) {
            sum -= ans2 - a[i];
            a[i] = ans2;
        }
        save[i] = sum;
    }
    // for (int i = 0; i < n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << "\n";
    // for (int i = 0; i < n; i++) {
    //     cout << save[i] << " ";
    // }
    // cout << "\n";
    cout << ans << " " << ans2 << " " << res << "\n";
    // cout << "---\n";
    cout << ans - ans2 << "\n";

    // for(int i = 0 ; i < )
// cout << ans - ans2 << '\n';
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