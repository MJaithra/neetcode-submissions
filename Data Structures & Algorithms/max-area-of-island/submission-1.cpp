class Solution {
public:
    vector<pair<int,int>> dirs = {
        {1,0},{0,1},{-1,0},{0,-1}
    };
    int dfs(int i, int j, int &m, int &n, vector<vector<int>>& grid)
    {
        grid[i][j] = 0;
        
        int area = 1;
        for(auto [di,dj] : dirs)
        {
            int ni = di+i;
            int nj = dj+j;

            if(ni>=0 && nj>=0 && ni<m && nj<n && grid[ni][nj]==1)
                area += dfs(ni, nj, m, n, grid);
            
        }

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int area = 0;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    int curr = dfs(i, j, m, n, grid);
                    area = max(area, curr);
                }
            }
        }

        return area;
    }
};
