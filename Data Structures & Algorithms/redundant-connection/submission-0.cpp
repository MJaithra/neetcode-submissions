class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int find(int x)
    { 
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b)
    {
        int rootA = find(a);
        int rootB = find(b);

        if(rootA == rootB)
            return;
        
        if(size[rootA] < size[rootB])
            swap(rootA, rootB);
        
        parent[rootB] = rootA;
        size[rootA]+= size[rootB];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        parent.resize(n);
        size.assign(n, 1);

        for(int i=0; i<n; i++)
        {
            parent[i]=i;
        }

        for(int i=0; i<edges.size(); i++)
        {
            int a = edges[i][0], b = edges[i][1];
            if(find(a) == find(b))
            {
                return {a,b};
            }
            else
                unite(a,b);
        }

        return vector<int>();
    }
};
