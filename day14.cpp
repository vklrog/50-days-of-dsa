//problem 1) 20. Valid Parentheses
class Solution {
public:
    bool solve(string& s, int& i,char chk){
        while(i<s.size()){
            char cur=s[i];
            i++;
            if(cur=='('){
                if(!solve(s,i,')')) return false;
            }else if(cur=='{'){
                if(!solve(s,i,'}')) return false;
            }else if(cur=='['){
                if(!solve(s,i,']')) return false;
            }else{
                return cur==chk;
            }
        }
        return chk=='x';
    }
    bool isValid(string s) {
        int i=0;
        return solve(s,i,'x');
    }
};