//problem1) 43. Multiply Strings
class Solution {
public:
    string addStrings(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string ans;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            ans.push_back(char(sum % 10 + '0'));
            carry = sum / 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string multiply(string num1, string num2) {
        string ans="0";
        if (num1 == "0" || num2 == "0") return "0";
        for(int i=num2.size()-1;i>=0;i--){
            int carry=0;
            int size=num2.size()-i-1;
            string par="";
            for(int j=num1.size()-1;j>=0;j--){
                int product=(num2[i]-'0')*(num1[j]-'0')+carry;
                par.push_back((product % 10) + '0');
                carry=product/10;
            }
            if(carry){
                par.push_back((carry)+'0');
            }
            reverse(par.begin(),par.end());
            while(size--){
                par.push_back('0');
            }
            ans=addStrings(ans,par);
        }
        int pos = 0;
        while (pos < ans.size() - 1 && ans[pos] == '0'){
            pos++;
            return ans.substr(pos);
        }
        return ans;
    }

};