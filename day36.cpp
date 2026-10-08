//problem 1) 301. Remove Invalid Parentheses
class Solution {
public:

    unordered_set<string> ans;
    void dfs(string &s, int i,int balance,int lrmove,int rrmove,string &path) {
        if (i == s.size()) {
            if (balance == 0 && lrmove == 0 && rrmove == 0) {
                ans.insert(path);
            }
            return;
        }
        char c = s[i];
        if (c == '(') {
            if (lrmove > 0) {
                dfs(s, i + 1,balance,lrmove - 1,rrmove,path);
            }
            path.push_back('(');
            dfs(s, i + 1,balance + 1,lrmove,rrmove,path);
            path.pop_back();
        }
        else if (c == ')') {
            if (rrmove > 0) {
                dfs(s, i + 1,balance,lrmove,rrmove- 1,path);
            }
            if (balance > 0) {
                path.push_back(')');
                dfs(s, i + 1,balance - 1,lrmove,rrmove,path);
                path.pop_back();
            }
        }
        else {
            path.push_back(c);
            dfs(s, i + 1,balance,lrmove,rrmove,path);
            path.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int lrmove = 0;
        int rrmove = 0;
        for (char c : s) {
            if (c == '(') {
                lrmove++;
            }
            else if (c == ')') {
                if (lrmove > 0){
                    lrmove--;
                }else{
                    rrmove++;
                }
            }
        }
        string path = "";
        dfs(s, 0,0,lrmove,rrmove,path);
        return vector<string>(ans.begin(), ans.end());
    }
};
//problem 2) 1021. Remove Outermost Parentheses
class Solution {
public:
    string removeOuterParentheses(string s) {
        string k="";
        int cnt=0;
        if(s[0]=='(') cnt=1;
        for(int i=1;i<s.size();){
            if(s[i]==')'){
                cnt--;
                if(cnt==0){
                    i+=2;
                    cnt=1;
                    continue;
                }else{
                    k.push_back(s[i]);
                }
            }else{
                cnt++;
                k.push_back(s[i]);
            }
            i++;
        }
        return k;
    }
};