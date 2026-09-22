//problem 1) B - Crimson Triples
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
 
void solve() {
    // Write your problem-solving logic here
    int n;
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++){
        long long mul = n/i;
        ans+=mul*mul;
    }
    cout<<ans<<"\n";
    
    
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t; 
    
    while (t--) {
        solve();
    }
    
    return 0;
}