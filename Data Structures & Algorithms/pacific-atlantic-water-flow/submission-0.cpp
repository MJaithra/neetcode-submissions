class Solution {
public:
// brute, raw solution
    vector<pair<int,int>> dirs = {
        {1,0},{0,1},{-1,0},{0,-1}
    };
    void dfsPacific(int i, int j, int m, int n, vector<vector<int>> &reach, vector<vector<int>>& heights)
    {
        if(reach[i][j] == 0)
            reach[i][j]=1;
        else if (reach[i][j] == 2)
            reach[i][j]=3;

        for(auto [di,dj] : dirs)
        {
            int ni=di+i, nj=dj+j;
            if(ni>=0 && nj>=0 && ni<m && nj<n && 
            heights[ni][nj] >= heights[i][j] &&
            reach[ni][nj]!=1 && reach[ni][nj]!=3)
            {
                dfsPacific(ni, nj, m, n, reach, heights);
            }
        }
    }
    void dfsAtlantic(int i, int j, int m, int n, vector<vector<int>> &reach, vector<vector<int>>& heights)
    {
        if(reach[i][j] == 0)
            reach[i][j]=2;
        else if (reach[i][j] == 1)
            reach[i][j]=3;

        for(auto [di,dj] : dirs)
        {
            int ni=di+i, nj=dj+j;
            if(ni>=0 && nj>=0 && ni<m && nj<n && 
            heights[ni][nj] >= heights[i][j] &&
            reach[ni][nj]!=2 && reach[ni][nj]!=3)
            {
                dfsAtlantic(ni, nj, m, n, reach, heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> reach(m,vector<int>(n,0));
        vector<vector<bool>> a(m, vector<bool>(n,false));

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 || j==0)
                    dfsPacific(i, j, m, n, reach, heights);
                if(i==m-1 || j==n-1)
                    dfsAtlantic(i, j, m, n, reach, heights);
            }
        }

        vector<vector<int>> res;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(reach[i][j] == 3)
                    res.push_back({i,j});
            }
        }

        return res;
    }
};
