class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> max;
        for(int i=0; i<points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];

            int dist = (x*x)+(y*y);
            max.push({dist, i});
            if(max.size() > k)
                max.pop();
        }

        vector<vector<int>> res;
        while(!max.empty())
        {
            int ind = max.top().second;
            max.pop();
            res.push_back(points[ind]);
        }

        return res;
    }
};
