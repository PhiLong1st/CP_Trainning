
/*
    Code by: KoKoDuDu
    Created: 19.12.2024 19:47:03
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
int n, m;
void move(string& dir, int& x, int& y, int& cnt)
{
    if (x == n && y == m) {
        if (dir != "UL") {
            dir = "UL";
            cnt++;
        }
    }
    else if (x == 1 && y == m) {
        if (dir != "DL") {
            dir = "DL";
            cnt++;
        }
    }
    else if (x == 1 && y == 1) {
        if (dir != "DR") {
            dir = "DR";
            cnt++;
        }
    }
    else if (x == n && y == 1) {
        if (dir != "UR") {
            dir = "UR";
            cnt++;
        }
    }
    else if (x == n) {
        if (dir == "DR") {
            dir = "UR";
            cnt++;
        }
        else if (dir == "DL") {
            dir = "UL";
            cnt++;
        }
    }
    else if (x == 1) {
        if (dir == "UR") {
            dir = "DR";
            cnt++;
        }
        else if (dir == "UL") {
            dir = "DL";
            cnt++;
        }
    }
    else if (y == 1) {
        if (dir == "UL") {
            dir = "UR";
            cnt++;
        }
        else if (dir == "DL") {
            dir = "DR";
            cnt++;
        }
    }
    else if (y == m) {
        if (dir == "UR") {
            dir = "UL";
            cnt++;
        }
        else if (dir == "DR") {
            dir = "DL";
            cnt++;
        }
    }

    if (dir == "DR") { x++; y++; }
    else if (dir == "DL") { x++; y--; }
    else if (dir == "UR") { x--; y++; }
    else if (dir == "UL") { x--; y--; }
}

void solve()
{
    int x, y, u, v;
    string dir;
    cin >> n >> m >> x >> y >> u >> v >> dir;
    if (x == u && y == v) {
        cout << "0\n";
        return;
    }
    int x1 = x, y1 = y, cnt = 0;
    string dir1 = dir;
    int res = 0;
    bool pass = false;

    map<tuple<int, int, string>, bool> mp;

    while (true) {
        if (mp.count({ x1, y1, dir1 })) {
            cout << "-1\n";
            return;
        }
        mp[{x1, y1, dir1}] = true;
        if (x1 == u && y1 == v) {
            cout << cnt << "\n";
            return;
        }
        pass = true;
        move(dir1, x1, y1, cnt);
    }
    cout << "-1\n";
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}