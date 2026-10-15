//problem 1) 2913. Subarrays Distinct Element Sum of Squares I
class Solution {
public:
    int sumCounts(std::vector<int>& nums) {
        int tot = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            unordered_set<int> del;
            for (int j = i; j < n; ++j) {
                del.insert(nums[j]);
                int dcnt = del.size();
                tot += (dcnt * dcnt);
            }
        }
        return tot;
    }
};
