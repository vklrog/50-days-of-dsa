//problem 1) 2267. Check if There Is a Valid Parentheses String Path
class Solution {
public:
    int n,m;
    int t[101][101][201];
    bool solve(vector<vector<char>>& grid,int i,int j,int cnt){
        cnt+=(grid[i][j]=='(')?1:-1;
        if(cnt<0){
            return false;
        }
        if(t[i][j][cnt] != -1) return t[i][j][cnt];
        if(i==n-1 && j==m-1 ){
            if(cnt==0) return t[i][j][cnt]=true;
            return t[i][j][cnt]=false;
        }
        if(i+1<n){
            if(solve(grid,i+1,j,cnt)){
                return t[i][j][cnt]=solve(grid,i+1,j,cnt);
            }
            
            
        }
        if(j+1<m){
            if(solve(grid,i,j+1,cnt)){
                return t[i][j][cnt]=solve(grid,i,j+1,cnt);
            }
        }
        return t[i][j][cnt]=false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(grid,0,0,0);
    }
};