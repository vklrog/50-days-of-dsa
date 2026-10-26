// problem 1) 3619. Count Islands With Total Value Divisible by K
class Solution {
public:
    int m;
    int n;
    int Mod;
    int dfs(vector<vector<int>>& grid,int r,int c){
        if(r>=n || r<0 || c>=m ||  c<0){
            return 0;
        }
        if(grid[r][c]==0){
            return 0;
        }
        int ans=0;
        if(grid[r][c]!=0){
            ans+=grid[r][c];
        }
        grid[r][c]=0;
        ans+=dfs(grid,r+1,c)%Mod;
        ans+=dfs(grid,r-1,c)%Mod;
        ans+=dfs(grid,r,c+1)%Mod;
        ans+=dfs(grid,r,c-1)%Mod;
        return ans%Mod;

    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        Mod=k;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    int t=dfs(grid,i,j);
                    if(t==0){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};