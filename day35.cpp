//problem 1) 38. Count and Say
class Solution {
public:

    string countAndSay(int n) {

        string s = "1";

        for(int i = 1; i < n; i++) {

            string ans = "";

            int count = 1;

            for(int j = 1; j < s.size(); j++) {

                if(s[j] == s[j-1]) {
                    count++;
                }
                else {
                    ans += to_string(count);
                    ans += s[j-1];

                    count = 1;
                }
            }

            ans += to_string(count);
            ans += s.back();

            s = ans;
        }

        return s;
    }
};