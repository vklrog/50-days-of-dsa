//problem 1) 96B - Lucky Numbers (easy)
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
vector<long long> v;
void solver(string curr,int cnt4,int cnt7,string s){
    if(curr.size()!=0){
        if(curr.size()>=s.size()  && cnt4==cnt7){
            if(stoll(curr)>=stoll(s)){
                v.push_back(stoll(curr));
                return;
            }
        }
        
    }
    if(curr.size()>s.size()+2){
        return;
    }
    solver(curr+'4',cnt4+1,cnt7,s);
    solver(curr+'7',cnt4,cnt7+1,s);
}
void solve() {
    // Write your problem-solving logic here
    int n;
    cin>>n;
    string s=to_string(n);
    string curr="";
    solver(curr,0,0,s);
    sort(all(v));
    cout<<v[0]<<"\n";
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
