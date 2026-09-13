//problem 1) 7. Reverse Integer
class Solution {
public:
    int reverse(int x) {
        int ans=0;
        int sign=1;
        string s=to_string(x);
        int k=0;
        if(s[k]=='-'){
            k++;
            sign=-1;
        }
        int i=s.size()-1;
        while(i>=k){
            int digit=s[i]-'0';
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && digit>7)){
                return 0;
            }
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && digit>8)){
                return 0;
            }
            ans=ans*10+digit;
            i--;
        }
        return sign*ans;

    }
};