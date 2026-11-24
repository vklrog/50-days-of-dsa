// problem 1) 3411. Maximum Subarray With Equal Products
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int cnt=INT_MIN;
        auto mx=max_element(begin(nums),end(nums));
        int mod=1e9+7;
        int pro;
        int lm;
        int gd;
        for(int i=0;i<nums.size();i++){
            pro=1;
            lm=1;
            gd=0;
            for(int j=i;j<nums.size();j++){
                pro=(1ll*pro*nums[j])%mod;
                gd=gcd(gd,nums[j]);
                lm=lcm(lm,nums[j]);
                if(pro==gd*lm){
                    cnt=max(cnt,j-i+1);
                }
            }
        }
        return cnt;
    }
};
