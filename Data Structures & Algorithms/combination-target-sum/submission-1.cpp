class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;

    void backtrack(int s, int &rem, vector<int> &nums)
    {
        if(rem == 0)
        {
            res.push_back(curr);
            return;
        }

        for(int i=s; i< nums.size(); i++)
        {
            if(nums[i] > rem)
                break;
            
            curr.push_back(nums[i]);
            rem-=nums[i];
            backtrack(i, rem, nums);

            rem+=nums[i];
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        backtrack(0, target, nums);
        return res;
    }
};
