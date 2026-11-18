// problem 1) 2914. Minimum Number of Changes to Make Binary String Beautiful
class Solution {
public:
    int minChanges(string s) {
        int i=0;
        int j=1;
        int cnt=0;
        while(i<s.size() && j<s.size()){
            if(s[i]!=s[j]){
                cnt++;
            }
            i+=2;
            j+=2;
        }
        return cnt;
    }
};