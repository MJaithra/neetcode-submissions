class Solution {
public:
    void dfs(int n, vector<bool> &visited, vector<vector<int>> &adj)
    {
        visited[n] = true;

        for(int nei : adj[n])
        {
            if(!visited[nei])
                dfs(nei, visited, adj);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> visited(n, false);
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                cnt+=1;
                dfs(i, visited, adj);
            }
        }

        return cnt;
    }
};
