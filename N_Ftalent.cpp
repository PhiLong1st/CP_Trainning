/*
    Code by: KoKoDuDu
    Created: 20.10.2024 01:00:21
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
vector<int>save;
bool check(string s) {
    int n = s.size();
    int u = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) return false;
        if (s[i] > s[i - 1]) {
            if (u == 1) return false;
            if (u == 0) {
                u = 1;
            }
        }
        else {
            if (u == 0) return false;
            if (u == 1) {
                u = 0;
            }
        }
    }
    return true;
}

void generate(int length, string current, char prev) {
    if (!check(current)) {
        return;
    }
    if (current.length() == length) {
        string tmp = current;
        for (int i = current.length() - 2; i >= 0; i--)
        {
            tmp += current[i];
        }
        // cout << tmp << '\n';
        int num = 0;
        for (int i = 0; i < tmp.size();i++)
        {
            num = num * 10 + (tmp[i] - '0');
        }
        save.push_back(num);
        return;
    }
    for (char d = '0'; d <= '9'; ++d) {
        if (prev == d) continue;
        generate(length, current + d, d);
    }
}
void solve() {
    int l, r, m;
    cin >> l >> r;
    for (int length = 3; length <= 7; length += 2) {
        generate((length + 1) / 2, "", '0');
    }
    int vtL = upper_bound(save.begin(), save.end(), (l - 1)) - save.begin();
    int vtR = upper_bound(save.begin(), save.end(), (r)) - save.begin() - 1;
    cout << vtR - vtL + 1 << '\n';
    cout << '[';
    for (int i = vtL; i <= vtR; ++i) {
        if (i == vtR) {
            cout << save[i];
        }
        else {
            cout << save[i] << ", ";
        }
    }
    cout << ']';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
    return 0;
}
