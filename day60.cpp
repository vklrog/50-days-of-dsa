// problem 1) 3665. Twisted Mirror Path Count
class Solution {
public:
    int n;
    int m;
    int dp[501][501][2];
    int MOD=1e9+7;
    int dfs(vector<vector<int>>& grid,int r,int c,int dir){
        if(r>=n || r<0 || c>=m || c<0) return 0;
        if(r==n-1 && c==m-1){
            return 1;
        }
        if(dp[r][c][dir]!=-1){
            return dp[r][c][dir];
        }
        if(grid[r][c]==1){
            if(dir==1){
                return dp[r][c][dir]=dfs(grid,r,c+1,0);
            }else{
                return dp[r][c][dir]=dfs(grid,r+1,c,1);
            }

        }
        int tot=0;
        tot=(tot+dfs(grid,r,c+1,0))%MOD;
        tot=(tot+dfs(grid,r+1,c,1))%MOD;
        return dp[r][c][dir]=tot;
        
    }
    int uniquePaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=dfs(grid,0,0,0);
        return ans;

    }
};
// problem 2) 453. Minimum Moves to Equal Array Elements
class Solution {
public:
    int minMoves(vector<int>& nums) {
        auto min_id=min_element(begin(nums),end(nums));
        long long mi=*min_id;
        long mit=0;
        for(int i=0;i<nums.size();i++){
            mit+=abs(mi-nums[i]);
        }
        return mit;
    }
};