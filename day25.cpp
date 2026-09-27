//problem 1) Apple division
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
ll temp=0;
ll mi=LLONG_MAX;;
ll ans=0;
void helper(const vector<int>& v,int i,ll sumA,ll sumB){
    if(i==v.size()){
        mi=min(mi,abs(sumA-sumB));
        return;
    }
    helper(v,i+1,sumA+v[i],sumB);
    helper(v,i+1,sumA,sumB+v[i]);
}
void solve() {
    // Write your problem-solving logic here
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        temp+=v[i];
    }
    helper(v,0,0,0);
    cout<<mi<<"\n";
    
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}