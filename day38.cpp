//problem 1) B. MEX Game
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    vector<int> freq(n + 1, 0);
 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }
 
    for (int i = 0; i <= n; i++) {
        if (freq[i] < 2 * k) {
            cout << (freq[i] == 2 * k - 1 ? "YES\n" : "NO\n");
            return;
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        solve();
    }
 
    return 0;
}
//problem 2) A - Robot Odd Moves
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int a, b;
    cin >> a >> b;
 
    if (a == 0) {
        if (b == 0) cout << 0 << '\n';
        else if (b == 1) cout << 1 << '\n';
        else cout << -1 << '\n';
        return;
    }
 
    if (b > a + 1) {
        cout << -1 << '\n';
    } else if ((a + b) % 2 == 0) {
        cout << a << '\n';
    } else {
        cout << a + 1 << '\n';
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) solve();
 
    return 0;
}
