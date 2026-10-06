//problem 1) 1371. Find the Longest Substring Containing Vowels in Even Counts
class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int,int> mp;
        mp[0]=-1;
        int bmsk=0;
        int result=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                bmsk^=(1<<(s[i]-'a'));
                if(mp.find(bmsk)!=mp.end()){
                    result=max(result,i-mp[bmsk]);
                }else{
                    mp[bmsk]=i;
                }
            }else{
                result=max(result,i-mp[bmsk]);

            }
        }
        return result;
    }
};
//problem 2) 921. Minimum Add to Make Parentheses Valid
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push(i);
            }else{
                if(s[st.top()]=='(' && s[i]==')'){
                    st.pop();
                }else{
                    st.push(i);
                }
            }

        }
        return st.size();
    }
};