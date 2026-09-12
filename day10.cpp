//problem 1) 3414. Maximum Score of Non-overlapping Intervals
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> k;
        int ma=0;
        int i=0;
        for(int j=0;j<s.size();j++){
            while(k.count(s[j])){
                k.erase(s[i]);
                i++;
            }
            k.insert(s[j]);
            ma=max(ma,j-i+1);
        }
        return ma;
    }
};