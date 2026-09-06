class Solution {
public:
// detect cycle - undirected graph - track parent
    bool hasCycle(int i, int parent, vector<bool> &visited, vector<vector<int>> &adj)
    {
        visited[i] = true;

        for(int nei : adj[i])
        {
            if(!visited[nei])
            {
                if(hasCycle(nei, i, visited, adj))
                    return true;
            }
            else if (nei != parent)
                return true;
        }

        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1)
            return false;
        
        vector<vector<int>> adj(n, vector<int>());
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> visited(n, false);
        bool cycle = hasCycle(0, -1, visited, adj);
        if(cycle)
            return false;
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
                return false;
        }

        return true;
    }
};
