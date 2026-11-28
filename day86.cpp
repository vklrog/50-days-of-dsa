// problem 1) B - Grapefruit Juice
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    long long n, k, x;
    cin >> n >> k >> x;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.rbegin(), a.rend());
    long long ans = sum;
    long long juice = 0;
    for (int i = n - 1; i >= k - 1; i -= k) {
        for (int j = 0; j < k; j++) {
            sum -= a[i - j];
        }
 
        juice += x;
 
        ans = max(ans, sum + juice);
    }
 
    cout << ans << '\n';
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