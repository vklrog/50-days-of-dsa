// problem 1) C. Books on a Shelf
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    vector<int> ans;
    ans.reserve(n);
    int cnt = 0;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && a[j] == a[i]) {
            j++;
        }
        ans.push_back(a[i]);
        cnt++;
        if (j - i > 1) {
            cnt++;
        }
        i = j;
    }
    for (int i = n - 1; i >= 0;) {
        int j = i;
        while (j >= 0 && a[j] == a[i]) {
            j--;
        }
        int freq = i - j;
        for (int k = 1; k < freq; k++) {
            ans.push_back(a[i]);
        }
        i = j;
    }
    cout << cnt << '\n';
    for (int x : ans) {
        cout << x << " ";
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        solve();
    }
 
    return 0;
}