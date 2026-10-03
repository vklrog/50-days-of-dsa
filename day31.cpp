// problem 1) 32. Longest Valid Parentheses
class Solution {
public:
    int longestValidParentheses(string s) {
        int op=0;
        int cl=0;
        if(s.size()==0)return 0;
        int mx=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                cl++;
            }else{
                op++;
            }
            if(cl==op){
                mx=max(mx,op+cl);
            }else if(cl>op){
                op=cl=0;
            }
        }
        op=0;
        cl=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')'){
                cl++;
            }else{
                op++;
            }
            if(cl==op){
                mx=max(mx,op+cl);
            }else if(op>cl){
                op=cl=0;
            }
        }
        return mx;
    }
};