class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //brute force - pattern - frequency map
        unordered_map<int, int> freq;
        for(int i =0; i< nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        vector<pair<int,int>> v ;
        for(auto &[num, count]: freq)
        {
            v.push_back({num, count});
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        vector<int> res;
        for(int i=0; i<k && i<v.size(); i++)
        {
            res.push_back(v[i].first);
        }

        return res;
    }
};
