//problem 1) 3551. Minimum Swaps to Sort by Digit Sum
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> digi(nums.size());
        vector<vector<int>> vp;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            int n=nums[i];
            while(n){
                sum+=n%10;
                n/=10;
            }
            vp.push_back({sum,nums[i],i});
        }
        sort(vp.begin(),vp.end(),[](const auto& a, const auto& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });
        int n=nums.size();
        vector<bool> vis(n, false);
        int cnt = 0;
        for (int i=0;i<n;i++){
            if (vis[i] || vp[i][2]==i) continue;
            int j=i;
            int cycsize=0;
            while (!vis[j]){
                vis[j]=true;
                j=vp[j][2];
                cycsize++;
            }
            cnt+=cycsize-1;
        }
        return cnt;
    }
};