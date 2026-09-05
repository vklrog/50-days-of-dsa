//problem(1)->2257C - Spying on the Beaver
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    // your code
    int n;
    cin>>n;
    vector<int> p(n+1);
    for(int i=2;i<=n;i++){
        cin>>p[i];
    }
    int m;
    cin>>m;
    cout<<m-1<<" ";
    vector<int> dam(m);
    for(int i=0;i<m;i++){
        cin>>dam[i];
    }
    sort(begin(dam),end(dam));
    for(int i=1;i<m;i++){
        cout<<dam[i]<<" ";
    }
    cout<<"\n";
    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        solve();
    }
}
// problem(2)->1647B - Madoka and the Elegant Gift
#include <bits/stdc++.h>
using namespace std;

void solve() {
    // your code
    int n,m;
    cin>>n>>m;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int cnt=0;
            if(i+1>=n || j+1>=m){
                continue;
            }
            cnt+=v[i][j]=='1'?1:0;
            cnt+=v[i+1][j]=='1'?1:0;
            cnt+=v[i][j+1]=='1'?1:0;
            cnt+=v[i+1][j+1]=='1'?1:0;
            if(cnt==4 || cnt==2 || cnt==1 || cnt==0){
                continue;
            }else{
                cout<<"NO"<<"\n";
                return;
            }
            
        }
    }
    cout<<"YES"<<"\n";
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
// problem(3)-> 1581B Diameter of Graph
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, m, k;
    cin >> n >> m >> k;

    long long mx = n * (n - 1) / 2;
    if (m < n - 1 || m > mx) {
        cout << "NO\n";
        return;
    }
    if (n == 1) {
        cout << (k > 1 ? "YES\n" : "NO\n");
        return;
    }

    if (m == mx) {
        cout << (k > 2 ? "YES\n" : "NO\n");
        return;
    }

    cout << (k > 3 ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
// problem(4)->3904. Smallest Stable Index II
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;
        vector<int> right(n);
        right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right[i] = min(right[i + 1], nums[i]);
        }
        int left_max = nums[0];
        for (int i = 0; i < n; ++i) {
            left_max = max(left_max, nums[i]); 
            if (left_max - right[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};