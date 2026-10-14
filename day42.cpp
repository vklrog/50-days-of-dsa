//problem 1)3723. Maximize Sum of Squares of Digits
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string k="";
        int i=9;
        int tot=0;
        int chk=sum;
        while(num && i>0 && sum!=0){
            if(sum/i>=1){
                int add=sum/i;
                sum-=i*add;
                while(add && num){
                    k.push_back(i+'0');
                    tot+=i;
                    add--;
                    num--;
                }
            }else{
                i--;
            }
        }
        if(tot<chk){
            return "";
        }
        while(num){
            k.push_back('0');
            num--;
        }
        return k;
    }
};
//problem 3) A - Perfect Sandwiches
 
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int a, b;
    cin >> a >> b;
 
    if (a <= b) {
        cout << -1 << "\n";
        return;
    }
 
    cout << min(a - b, b) << "\n";
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
//problem 3) C - Subarrays
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    vector<ll> pref(n + 1, 0);
 
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        pref[i] = pref[i - 1] + x;
    }
 
    vector<int> freq(k, 0);
    ll ans = 0;
 
    for (int r = 1; r <= n; r++) {
        if (r - k - 1 >= 0) {
            int rem = pref[r - k - 1] % k;
            freq[rem]++;
        }
 
        int rem = pref[r] % k;
        ans += freq[rem];
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