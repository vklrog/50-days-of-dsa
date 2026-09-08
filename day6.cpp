// problem 1) 2227D - Palindromex
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int sz = 2 * n;
    vector<int> a(sz);
    vector<int> zero;
    for (int i = 0; i < sz; i++) {
        cin >> a[i];
        if (a[i] == 0)
            zero.push_back(i);
    }
    int answer = 1;
    for (int z : zero) {
        vector<bool> present(n, false);
        present[0] = true;
        int l = z - 1;
        int r = z + 1;
        while (l >= 0 && r < sz && a[l] == a[r]) {
            present[a[l]] = true;
            l--;
            r++;
        }
        int mex = 0;
        while (mex < n && present[mex]){
            mex++;
        }
        answer = max(answer, mex);
    }
    int L = zero[0];
    int R = zero[1];
    vector<bool> present(n, false);
    int l = L;
    int r = R;
    bool palindrome = true;
    while (l <= r) {
        if (a[l] != a[r]) {
            palindrome = false;
            break;
        }
        present[a[l]] = true;
        present[a[r]] = true;
        l++;
        r--;
    }
    if (palindrome) {
        l = L - 1;
        r = R + 1;
        while (l >= 0 && r < sz && a[l] == a[r]) {
            present[a[l]] = true;
            l--;
            r++;
        }
        int mex = 0;
        while (mex < n && present[mex]){
            mex++;
        }
        answer = max(answer, mex);
    }
    cout << answer << '\n';
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
//2)3870. Count Commas in Range
class Solution {
public:
    int countCommas(int n) {
        if(n<1000){
            return 0;
        }
        return(n-1000+1);
    }
};