class Solution {
public:
    void backtrack(int i, int &rem, vector<int>& nums, vector<int> &curr, vector<vector<int>>& res)
    {
        if( rem == 0)
        {
            res.push_back(curr);
            return;
        }

        if(rem < 0 || i == nums.size())
            return;
        
        curr.push_back(nums[i]);
        rem-= nums[i];
        backtrack(i,rem, nums, curr, res );

        int n = curr.back();
        curr.pop_back();
        rem+=n;
        backtrack(i+1, rem, nums, curr, res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        int rem = target;
        int i = 0;

        backtrack(i, rem, nums, curr, res);

        return res;
    }
};
