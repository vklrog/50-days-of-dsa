// problem 1) 462. Minimum Moves to Equal Array Elements II
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int idx=nums.size()/2;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=abs(nums[i]-nums[idx]);
        }
        return ans;
    }
};