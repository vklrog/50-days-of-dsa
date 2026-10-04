//problem 1) 678. Valid Parenthesis String
class Solution {
public:
    vector<vector<int>> t;
    bool solver(string& s, int i, int balance) {
        if (balance < 0) return false;
        if (i == s.size()) {
            return balance == 0;
        }
        if (t[i][balance] != -1) {
            return t[i][balance];
        }
        if (s[i] == '(') {
            return t[i][balance] = solver(s, i + 1, balance + 1);
        }
        if (s[i] == ')') {
            return t[i][balance] = solver(s, i + 1, balance - 1);
        }
        bool op1 = solver(s, i + 1, balance + 1);
        bool op2 = solver(s, i + 1, balance - 1);
        bool op3 = solver(s, i + 1, balance);
        return t[i][balance] = (op1 || op2 || op3);
    }
    bool checkValidString(string s) {
        int n = s.size();
        t.assign(n, vector<int>(n + 1, -1));
        return solver(s, 0, 0);
    }
};

//problem 2) 1915. Number of Wonderful Substrings
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int xo=0;
        long long result=0;
        for(int i=0;i<word.size();i++){
            int shift=word[i]-'a';
            xo^=(1<<shift);
            result+=mp[xo];
            for(char ch='a';ch<='j';ch++){
                int check=xo^(1<<(ch-'a'));
                result+=mp[check];
            }
            mp[xo]++;
        }
        return result;
    }
};