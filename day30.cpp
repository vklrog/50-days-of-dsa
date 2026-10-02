//problem 1) 1759. Count Number of Homogenous Substrings
class Solution {
public:
    int countHomogenous(string s) {
        long long cnt=1;
        char ch=s[0];
        const long long mod=1e9+7;
        long long res=0;
        for(int i=1;i<s.size();i++){
            if(ch==s[i]){
                cnt++;
            }else{
                res=res+(cnt*(cnt+1)/2)%mod;
                cnt=1;
                ch=s[i];
            }
        }
        res=res+(cnt*(cnt+1)/2)%mod;
        return res;
    }
};
//problem 2) 1446. Consecutive Characters
class Solution {
public:
    int maxPower(string s) {
        char ch=s[0];
        int cnt=1;
        int mx=INT_MIN;
        for(int i=1;i<s.size();i++){
            if(ch==s[i]){
                cnt++;
                mx=max(cnt,mx);
            }else{
                cnt=1;
                ch=s[i];
            }
        }
        return (mx==INT_MIN)?1:mx;
    }
};
//problem 3) 1209. Remove All Adjacent Duplicates in String II
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push({s[i],1});
            }else{
                auto [ch,cnt]=st.top();
                if(ch==s[i]){
                    cnt++;
                    st.push({ch,cnt});
                    if(cnt==k){
                        while(!st.empty() && st.top().first==ch){
                            st.pop();
                        }

                    }
                }else{
                    st.push({s[i],1});
                }
            }

        }
        string p="";
        while(!st.empty()){
            p+=st.top().first;
            st.pop();
        }
        reverse(begin(p),end(p));
        return p;
    }
};