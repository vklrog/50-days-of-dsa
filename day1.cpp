class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mi=nums1[0];
        bool ans=false;
        for(int i=0;i<nums1.size();i++){
            mi=min(mi,nums1[i]);
            if(nums1[i]%2==1){
                ans=true;
            }
        }
        if(mi%2==1){
            return ans;
        }
        return !ans;
    }
};