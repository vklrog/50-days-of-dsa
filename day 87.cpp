//problem 1) A - Picnic for Two
#include <bits/stdc++.h> 

void solve() {
    int l,a,b;
    cin>>l>>a>>b;
    vector<bool> aa(l);
    vector<bool> bb(l);
    for(int i=0;i<l;i++){
        if(!aa[i*a%l]){
            aa[i*a%l]=true;
        }else{
            break;
        }
        
    }
    for(int i=0;i<l;i++){
        if(!bb[i*b%l]){
            bb[i*b%l]=true;
        }else{
            break;
        }
        
    }
    int cnt=0;
    for(int i=0;i<l;i++){
        if(aa[i]==true && bb[i]==true) cnt++;
        
    }
    cout<<cnt<<endl;
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
