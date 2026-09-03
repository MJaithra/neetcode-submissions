class Solution {
public:
// number of connected components
    bool exists(int i, int j, int &m, int &n)
    {
        return i>=0 && j>=0 && i<m && j<n;
    }
    void dfs(int i, int j, int m, int n, vector<vector<bool>> &visited, vector<vector<char>>& grid )
    {
        visited[i][j] = true;

        if(exists(i+1,j,m,n) && !visited[i+1][j] && grid[i+1][j]=='1')
            dfs(i+1, j, m, n, visited, grid);
        if(exists(i,j+1,m,n) && !visited[i][j+1] && grid[i][j+1]=='1')
            dfs(i, j+1, m, n, visited, grid);
        if(exists(i-1,j,m,n) && !visited[i-1][j] && grid[i-1][j]=='1')
            dfs(i-1, j, m, n, visited, grid);
        if(exists(i,j-1,m,n) && !visited[i][j-1] && grid[i][j-1]=='1')
            dfs(i, j-1, m, n, visited, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        int islands = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')
                {
                    islands++;
                    dfs(i, j, m, n, visited, grid);
                }
            }
        }

        return islands;
    }
};
