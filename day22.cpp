//problem 1) weird algorithm
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())

// Constants
const int MOD = 1e9 + 7; // 1000000007
const ll INF = 1e18;

void solve(int n) {
    // Write your problem-solving logic here
    if(n==1){
        cout<<1<<"\n";
        return;
    }
    cout<<n<<" ";
    if(n%2==0){
        solve(n/2);
    }else{
        solve(n*3+1);
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>> n;
    solve(n);
    
    return 0;
}
//problem 2) 476B - Dreamoon and WiFi
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())

// Constants
const int MOD = 1e9 + 7; // 1000000007
const ll INF = 1e18;
double find(int pos,int cur,int n){
    if(n==0){
        if(cur==pos){
            return 1;
        }
        return 0;
    }
    double res=0;
    res+=find(pos,cur+1,n-1)+find(pos,cur-1,n-1);
    return res;
}
void solve() {
    // Write your problem-solving logic here
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    int pos=0;
    for(auto i:s1){
        if(i=='+'){
            pos+=1;
        }else{
            pos-=1;
        }
    }
    int cur=0;
    int n=0;
    for(auto i:s2){
        if(i=='+'){
            cur+=1;
        }else if(i=='-'){
            cur-=1;
        }else{
            n++;
        }
    }
    double res=find(pos,cur,n);
    double di=pow(2,n);
    if(n==0){
        if(pos==cur){
            cout<<fixed<<setprecision(12)<<1.0<<"\n";
            return;
        }else{
            cout<<fixed<<setprecision(12)<<0.0<<"\n";
        }
    }else{
        cout<<fixed<<setprecision(12)<<res/di<<"\n";
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
// problem 3) 3550. Smallest Index With Digit Sum Equal to Index
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            int h=0;
            while(n){
                h+=n%10;
                n/=10;
            }
            if(h==i){
                return i;
            }
        }
        return -1;
    }
};