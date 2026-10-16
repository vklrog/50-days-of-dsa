//problem 1) C. AND, OR, Sort!
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (s[0] == '1') {
        cout << count(s.begin(), s.end(), '0') << '\n';
        return;
    }

    int ones = 0;
    int zeros = count(s.begin(), s.end(), '0');
    int ans = zeros;

    for (char c : s) {
        if (c == '0') {
            zeros--;
        } else {
            ones++;
        }

        ans = min(ans, ones + zeros);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}