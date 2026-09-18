//problem 1) 1520. Maximum Number of Non-Overlapping Substrings
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> str(26,-1);
        vector<int> end(26);
        for(int i=0;i<s.size();i++){
            if(str[s[i]-'a']==-1){
                str[s[i]-'a']=i;
            }
            end[s[i]-'a']=i;
        }
        vector<int> isvalid(26,true);
        for(int k=0;k<26;k++){
            if(str[k]==-1) continue;
            for(int i=str[k];i<=end[k];i++){
                if(str[s[i]-'a']<str[k]){
                    isvalid[k]=false;
                    break;
                }
                end[k]=max(end[s[i]-'a'],end[k]);
            }
        }
        int last=INT_MAX;
        vector<string> ans;
        for(int i=s.size()-1;i>=0;i--){
            int idx=s[i]-'a';
            if(!isvalid[idx]){
                continue;
            }
            if(i==str[idx] && end[idx]<last){
                ans.push_back(s.substr(i,end[idx]-i+1));
                last=i;
            }
        }
        return ans;
    }
};