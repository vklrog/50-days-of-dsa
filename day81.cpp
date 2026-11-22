// problem 1) 2124. Check if All A's Appears Before All B's
class Solution {
public:
    bool checkString(string s) {
        int i=0;
       while(i<s.size()){
        if(s[i]=='a'){
            i++;
        }else{
            break;
        }
       } 
       int j=i;
       while(j<s.size()){
        if(s[j]=='b'){
            j++;
        }else{
            break;
        }
       }
       if(j==s.size()){
        return true;
       }
       return false;
    }
};