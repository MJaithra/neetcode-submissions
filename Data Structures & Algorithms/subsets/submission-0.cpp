class Solution {
public:
    void backtrack(int i, vector<int>& nums, vector<int> &curr, vector<vector<int>> &result)
    {
        if( i == nums.size())
        {
            result.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        backtrack(i+1, nums, curr, result);

        curr.pop_back();
        backtrack(i+1, nums, curr, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(0, nums, curr, result);
        return result;
    }
};
