    class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(char x : tasks)
        {
            mp[x]++;
        }        

        priority_queue<int> hp;
        queue<pair<int, int>> q; // time, freq

        for(auto x : mp)
        {
            hp.push(x.second);
        }

        int time=0;
        while(!hp.empty() || !q.empty())
        {
            time++;

            if(!hp.empty())
            {
                int cnt = hp.top();
                cnt--;
                if(cnt > 0)
                {
                    q.push({time+n, cnt});
                }
                hp.pop();
            }
            else
            {
                auto x = q.front();
                time = x.first;
            }

            if(!q.empty() && q.front().first == time)
            {
                hp.push(q.front().second);
                q.pop();
            }
            
        }

        return time;

    }
};
