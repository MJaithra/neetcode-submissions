class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //  build adjacency list
        vector<vector<pair<int,int>>> graph(n+1);
        for(int i=0; i<times.size(); i++)
        {
            auto t = times[i];
            graph[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

        pq.push({0, k});

        while(!pq.empty())
        {
            auto [currDist, node] = pq.top();
            pq.pop();

            if(currDist > dist[node])
                continue;

            for(auto [nei, weight] : graph[node])
            {
                if(currDist + weight < dist[nei])
                {
                    dist[nei] = currDist+weight;
                    pq.push({dist[nei], nei});
                }
            }
        }
        int minTime = *max_element(dist.begin()+1, dist.end());
        return minTime == INT_MAX ? -1 : minTime;
    }
};
