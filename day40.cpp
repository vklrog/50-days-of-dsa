//problem 1) 2897. Apply Operations on Array to Maximize Sum of Squares

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<int> cnt(32, 0);
        for (int x : nums) {
            for (int b = 0; b < 32; b++) {
                if (x & (1LL << b)) {
                    cnt[b]++;
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            long long num = 0;
            for (int b = 0; b < 32; b++) {
                if (cnt[b] > 0) {
                    num |= (1LL << b);
                    cnt[b]--;
                }
            }
            ans = (ans + num * num) % MOD;
        }
        return ans;
    }
};
