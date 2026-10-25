// problem 1) 1254. Number of Closed Islands
class Solution {
public:
    int n;
    int m;
    bool dfs(vector<vector<int>>& grid,int r,int c){
        if(r>=n || r<0 || c>=m || c<0){
            return false;
        }
        if(grid[r][c]==1){
            return true;
        }
        grid[r][c]=1;
        bool lef=dfs(grid,r,c-1);
        bool rig=dfs(grid,r,c+1);
        bool up=dfs(grid,r-1,c);
        bool dow=dfs(grid,r+1,c);
        return lef && rig && up && dow;
    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    if(dfs(grid,i,j)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};