class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int comps;
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
        size[rootA] += size[rootB];
        comps--;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        comps = n;
        parent.resize(n);
        size.assign(n,1);

        for(int i=0; i<n; i++)
        {
            parent[i] = i;
        }

        for(int i=0; i<edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];

            if(find(a) == find(b))
                return false;
            
            unite(a,b);
        }

        return comps==1;
    }
};
