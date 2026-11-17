// problem )1 130. Surrounded Regions
class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n) return;
        if (visited[r][c]) return;
        if (grid[r][c] != 'O') return;
        visited[r][c] = true; 
        dfs(r + 1, c, grid, visited); 
        dfs(r - 1, c, grid, visited); 
        dfs(r, c + 1, grid, visited); 
        dfs(r, c - 1, grid, visited); 
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            if(board[i][0]=='O') dfs(i,0,board,vis);
            if(board[i][n-1]=='O') dfs(i,n-1,board,vis);
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O') dfs(0,j,board,vis);
            if(board[m-1][j]=='O') dfs(m-1,j,board,vis);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==true){
                    continue;
                }else{
                    board[i][j]='X';
                }
            }
        }
    }
};