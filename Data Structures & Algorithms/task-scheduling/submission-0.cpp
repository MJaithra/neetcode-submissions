    class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(char x : tasks)
        {
            mp[x]++;
        }        

        priority_queue<pair<int, char>> hp;
        queue<pair<int, pair<int, char>>> q; // time, freq, char

        for(auto x : mp)
        {
            cout<<x.second<<" "<<x.first<<endl;
            hp.push({x.second, x.first});
        }

        int time=0;
        while(!hp.empty() || !q.empty())
        {
            if(!hp.empty())
            {
                auto x = hp.top();
                time++;
                if(x.first > 1)
                {
                    q.push({time+n, {x.first-1, x.second}});
                }
                hp.pop();
            }
            else
            {
                auto x = q.front();
                time = x.first;
            }

            while(!q.empty())
            {
                auto x = q.front();
                if(x.first <= time)
                {
                    hp.push(x.second);
                    q.pop();
                }
                else
                    break;
            }
            
        }

        return time;

    }
};
