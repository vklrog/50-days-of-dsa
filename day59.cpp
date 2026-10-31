//problem 1) 6. Zigzag Conversion
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows);
        int dir=1;
        int j=0;
        if(numRows == 1) return s;
        for(int i=0;i<s.size();i++){
            if(dir==1){
                rows[j]+=s[i];
                if(j==numRows-1){
                    j=j-1;
                    dir=-1;
                }else{
                    j++;
                }
            }else if(dir==-1){
                rows[j]+=s[i];
                if(j==0){
                    dir = 1;
                    j++;
                }else{
                    j--;
                }
            }
        }
        string ans = "";
        for(auto x : rows){
            ans += x;
        }
        return ans;
    }
};