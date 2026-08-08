class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        vector<int> res;
        for(int i=0; i< nums.size(); i++)
        {
            int need = target - nums[i];
            if(seen.count(need))
            {
                res.push_back(seen[need]);
                res.push_back(i);
                return res;
            }
            seen[nums[i]] = i;
        }

        return res;
    }
};
