//problem 1) 856. Score of Parentheses
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<pair<char,int>> st;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push({s[i],0});
            }else{
                if(s[i]==')'){
                    int pw=st.top().second;
                    int xtr=2;
                    if(pw==0){
                        xtr=1;
                    }else{
                        xtr*=pw;
                    }
                    st.pop();
                    if(!st.empty()){
                        st.top().second+=xtr;
                    }else{
                        ans+=xtr;
                    }
                }else{
                    st.push({s[i],0});
                }
            }
        }
        return ans;
    }
};
