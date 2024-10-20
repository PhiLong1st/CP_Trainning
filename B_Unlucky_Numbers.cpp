

/*
    Code by: KoKoDuDu
    Created: 14.10.2024 13:57:29
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
vector<int> num;
int a, b, d, k;
int DP[18][10][10][2];

/// DP[p][minn][maxx][f] = number <= b from this state has the minimum digit is minn, maximum digit is maxx
/// p = current position from left side (zero based)
/// minn = the minimum number we have placed so far
/// maxx = the maximum number we have placed so far
/// f = the number we are building has already become smaller than b? [0 = no, 1 = yes]

int call(int pos, int minn, int maxx, int f) {
    if (pos == num.size()) {
        return 1;
    }
    cerr << pos << " " << minn << " " << maxx << " " << f << '\n';
    if (DP[pos][minn][maxx][f] != -1) return DP[pos][minn][maxx][f];
    int res = 0;
    int LMT = (f == 0) ? num[pos] : 9LL;
    for (int dgt = 0; dgt <= LMT; dgt++) {
        int nf = f;
        if (f == 0 && dgt < LMT) nf = 1; /// The number is getting smaller at this position
        int tmp_minn = min(minn, dgt);
        int tmp_maxx = max(maxx, dgt);
        if (tmp_minn == minn && tmp_maxx == maxx) res += call(pos + 1, minn, maxx, nf);
    }
    return DP[pos][minn][maxx][f] = res;
}
int calc(int b) {
    num.clear();
    while (b > 0) {
        num.push_back(b % 10);
        b /= 10;
    }
    // for (int g : num) { cout << g << " "; }
    reverse(num.begin(), num.end());
    memset(DP, -1, sizeof(DP));
    int res = call(0, 1, 9, 0);
    return res;
}
void solve() {
    string l, r;
    cin >> l >> r;
    if (l.size() < r.size()) {
        for (int i = 1; i <= l.size(); ++i) {
            cout << '9';
        }
        cout << '\n';
    }
    else {

    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cout << calc(20);
    // cin >> t;
    // while (t--) {
    //     solve();
    // }
    return 0;
}