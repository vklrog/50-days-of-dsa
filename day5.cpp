// problem 1) 940. Distinct Subsequences II
class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> vis(26, 0);
        vector<long long> dp(s.size() + 1, 0);
        const int MOD = 1e9 + 7;
        dp[0] = 1;
        int i = 1;
        for (char c : s) {
            dp[i] = (2 * dp[i - 1]) % MOD;
            if (vis[c - 'a'] != 0) {
                dp[i] = (dp[i] - dp[vis[c - 'a'] - 1] + MOD) % MOD;
            }
            vis[c-'a'] = i;
            i++;
        }
        return (dp[s.size()]-1+MOD)%MOD;
    }
};