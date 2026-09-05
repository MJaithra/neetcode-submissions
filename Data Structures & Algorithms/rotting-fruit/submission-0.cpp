class Solution {
public:
    // multisource bfs from all rotten oranges - at the end see if there are any fresh left -> return -1
    // else return max level
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }

        q.push({-1,-1});

        int ans = -1;
        vector<pair<int,int>> dirs = {
            {1,0},{0,1},{-1,0},{0,-1}
        };

        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();

            if(p.first == -1 && p.second==-1)
            {
                ans++;
                if(!q.empty())
                    q.push({-1,-1});
            }

            int i=p.first, j = p.second;
            for( auto [di,dj] : dirs)
            {
                int ni = i+di, nj=j+dj;
                if(ni>=0 && nj>=0 && ni<m && nj<n && grid[ni][nj]==1)
                {
                    grid[ni][nj] = 2;
                    q.push({ni,nj});
                }
            }
        }

        // if there is any 1 left - return -1 else return ans
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }

        return ans;
    }
};
