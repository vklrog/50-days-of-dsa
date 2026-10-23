//problem 1) 3644. Maximum K to Sort a Permutation
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int t=0;
        bool first=true;
        int ans=0;
        vector<bool> vis(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==i){
                continue;
            }
            if(vis[i]==true){
                continue;
            }
            int j=i;
            int curr=nums[i];
            while(curr!=j){
                if(first){
                    t=curr;
                    first = false;
                }else{
                    t&=curr; 
                }
                vis[curr]=true;
                curr=nums[curr]; 
            }
            t&=curr;
            vis[curr]=true;
        }
        return t;
    }
};