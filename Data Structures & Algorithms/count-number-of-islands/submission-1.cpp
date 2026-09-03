class Solution {
public:
// number of connected components
// using the same grid instead of explicit vsisited matrix
vector<pair<int,int>> dirs = {
    {1,0},{0,1},{-1,0},{0,-1}
};
    void dfs(int i, int j, int m, int n, vector<vector<char>>& grid )
    {
        grid[i][j] = '0';

        for(auto [di,dj] : dirs)
        {
            int ni = i+di;
            int nj = j+dj;

            if(ni>=0 && nj>=0 && ni<m && nj<n && grid[ni][nj]=='1')
                dfs(ni, nj, m, n, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]=='1')
                {
                    islands++;
                    dfs(i, j, m, n, grid);
                }
            }
        }

        return islands;
    }
};
