

/*
    Code by: KoKoDuDu
    Created: 20.10.2024 01:42:40
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> results(10, vector<string>());

void generateNumbers(int length, string current, char prev) {
    if (current.length() == length) {
        char last_digit = current.back();
        if (current.find(last_digit) == current.size() - 1) {
            results[length].push_back(current);
        }
        return;
    }

    for (char digit = prev; digit <= '9'; ++digit) {
        generateNumbers(length, current + digit, digit);
    }
}

void solve() {
    int max_length;
    cin >> max_length;
    for (int length = 1; length <= max_length; length += 2) {
        generateNumbers(length, "", '1');
    }
    for (int length = 1; length <= max_length; length += 2) {
        for (string num : results[length]) {
            cout << num << '\n';
        }
    }
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}