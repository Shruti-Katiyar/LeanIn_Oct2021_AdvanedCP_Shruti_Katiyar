//number of islands
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';
        int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<8; i++) {
            int newX = x+dx[i];
            int newY = y+dy[i];
            if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]=='1')
                dfs(grid, newX, newY);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
          int n = grid.size(), m = grid[0].size();
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]=='1') {
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    
    }
};

