class Solution {
public:
    int robRange(vector<int> &nums, int start, int end)
    {
        int n = nums.size();
        vector<int> dp(n+2,0);
        for(int i=end; i>=start; i--)
        {
            dp[i] = max( nums[i]+dp[i+2], dp[i+1]);
        }
        return dp[start];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        int c1 = robRange(nums, 0, n-2);
        int c2 = robRange(nums, 1, n-1);

        return max(c1,c2);
    }
};
