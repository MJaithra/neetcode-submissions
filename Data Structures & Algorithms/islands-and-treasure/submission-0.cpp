class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 0)
                    q.push({i,j});
            }
        }

        vector<pair<int,int>> dirs = {
            {1,0},{0,1},{-1,0},{0,-1}
        };

        while(!q.empty())
        {
            auto [i,j] = q.front();
            q.pop();

            for(auto [di,dj] : dirs)
            {
                int ni = i+di, nj = j+dj;
                if(ni>=0 && nj >=0 && ni<m && nj<n && grid[ni][nj] == INT_MAX)
                {
                    grid[ni][nj] = 1+grid[i][j];
                    q.push({ni, nj});
                }
            }
        }

        return;
    }
};
