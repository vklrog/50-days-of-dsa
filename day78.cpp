// problem 1) 2567. Minimum Score by Changing Two Elements
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int min_cst=min(abs(nums[2]-nums[n-1]),abs(nums[n-3]-nums[0]));
        min_cst=min(min_cst,abs(nums[n-2]-nums[1]));
        return min_cst;
    }
};