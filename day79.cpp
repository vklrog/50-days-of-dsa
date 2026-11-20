// problem 1) 3041. Maximize Consecutive Elements in an Array After Modification
class Solution {
public:
    vector<vector<int>> v;
    int find(vector<int>&nums,int i,int target){
        int j=lower_bound(begin(nums)+i,end(nums),target)-begin(nums);
        if(j<nums.size() && nums[j]==target){
            return j;
        }
        return -1;
    }
    int solve(int i,int ad_on,vector<int>& nums){
        if(v[i][ad_on]!=-1){
            return v[i][ad_on];
        }
        int curr=nums[i]+ad_on;
        int fnd=find(nums,i+1,curr);
        int ans=1;
        if(fnd!=-1){
            ans=max(ans,1+solve(fnd,1,nums));
        }
        fnd=find(nums,i+1,curr+1);
        if(fnd!=-1){
            ans=max(ans,1+solve(fnd,0,nums));
        }
        return v[i][ad_on]=ans;
    }
    int maxSelectedElements(vector<int>& nums) {
        sort(begin(nums),end(nums));
        v.assign(nums.size()+1,vector<int>(2,-1));
        int ans=1;
        for(int i=0;i<nums.size();i++){
            ans=max({ans,solve(i,0,nums),solve(i,1,nums)});
        }
        return ans;
    }
};