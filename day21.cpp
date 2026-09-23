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
vector<long long> dp;

long long recur(int n) {
    if (n == 0)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    long long sum = 0;

    for (int i = 1; i <= 6; i++) {
        if (n - i < 0) break;
        sum = (sum + recur(n - i)) % MOD;
    }

    return dp[n] = sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    dp.resize(n+1,-1);
    long long ans=recur(n);
    cout<<ans<<"\n";
    
    return 0;
}
