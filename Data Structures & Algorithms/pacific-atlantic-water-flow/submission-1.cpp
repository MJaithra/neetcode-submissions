class Solution {
public:
// cleaner code
    vector<pair<int,int>> dirs = {
        {1,0},{0,1},{-1,0},{0,-1}
    };
    
    void dfs(int i, int j, int m, int n, vector<vector<bool>> &visited, vector<vector<int>>& heights)
    {
        visited[i][j] = true;

        for(auto [di,dj] : dirs)
        {
            int ni=di+i, nj=dj+j;
            if(ni>=0 && nj>=0 && ni<m && nj<n && 
            heights[ni][nj] >= heights[i][j] && !visited[ni][nj])
            {
                dfs(ni, nj, m, n, visited, heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m, vector<bool>(n,false));

        for(int i=0; i<m; i++)
        {
            dfs(i, 0, m, n, pacific, heights);
            dfs(i, n-1, m, n, atlantic, heights);
        }

        for(int j=0; j<n; j++)
        {
            dfs(0, j, m, n, pacific, heights);
            dfs(m-1, j, m, n, atlantic, heights);
        }

        vector<vector<int>> res;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                    res.push_back({i,j});
            }
        }

        return res;
    }
};
