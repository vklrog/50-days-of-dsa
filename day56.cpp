//problem 1) 13. Roman to Integer
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int prev=-1;
        int tot=0;
        for(int i=0;i<s.size();i++){
            if(prev==-1){
                tot+=m[s[i]];
                prev=m[s[i]];
            }else{
                if(prev<m[s[i]]){
                    tot+=m[s[i]];
                    tot-=2*(prev);
                    prev=m[s[i]];
                }else{
                    tot+=m[s[i]];
                    prev=m[s[i]];
                }
            }
        }
        return tot;
        
    }
};