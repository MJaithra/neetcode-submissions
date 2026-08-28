class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;

    void backtrack(vector<bool> &used, vector<int> &nums)
    {
        if( curr.size() == nums.size())
        {
            res.push_back(curr);
            return;
        }
        
        for(int i=0; i< nums.size(); i++)
        {
            if(used[i])
                continue;
            
            curr.push_back(nums[i]);
            used[i] = true;

            backtrack(used, nums);

            curr.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>used(nums.size(), false);
        backtrack(used, nums);
        return res;
    }
};
