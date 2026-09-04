//2078B - Vicious Labyrinth codeforces
#include <bits/stdc++.h>
using namespace std;

void solve() {
    // your code
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    if(k%2==0){
        for(int i=0;i<n;i++){
            v[i]=n-1;
        }
        v[n-2]=n;
    }else{
        for(int i=0;i<n;i++){
            v[i]=n;
        }
        v[n-1]=n-1;
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
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