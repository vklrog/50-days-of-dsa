// problem 1) 3736. Minimum Moves to Equal Array Elements III
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int tot=accumulate(begin(nums),end(nums),0);
        auto mx=max_element(begin(nums),end(nums));
        int sz=nums.size();
        return sz*(*mx)-tot;
    }
};