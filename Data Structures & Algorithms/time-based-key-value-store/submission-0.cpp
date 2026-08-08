class TimeMap {
public:
    unordered_map<string,vector<pair<string, int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>> v = mp[key];
        int left=0, right = v.size()-1;
        string res ="";

        while(left <= right)
        {
            int mid = left + (right-left)/2;

            if(v[mid].second <= timestamp)
            {
                res = v[mid].first;
                left = mid+1;
            }
            else
                right = mid-1;
        }

        return res;
    }
};
