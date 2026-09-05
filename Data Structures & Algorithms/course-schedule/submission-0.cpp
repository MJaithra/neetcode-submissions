class Solution {
public:
    // topological sort
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses, 0);
        int m = prerequisites.size();
        for(int i=0; i<m; i++)
        {
            indeg[prerequisites[i][0]]+=1;
        }

        queue<int> q;
        for(int i=0; i< numCourses; i++)
        {
            if(indeg[i] == 0)
                q.push(i);
        }

        vector<int> order;
        while(!q.empty())
        {
            int n = q.front();
            q.pop();

            order.push_back(n);
            for(int i=0; i<m; i++)
            {
                if(prerequisites[i][1] == n)
                {
                    indeg[prerequisites[i][0]]--;
                    if(indeg[prerequisites[i][0]] == 0)
                        q.push(prerequisites[i][0]);
                }
                
            }
        }

        return order.size() == numCourses;

    }
};
