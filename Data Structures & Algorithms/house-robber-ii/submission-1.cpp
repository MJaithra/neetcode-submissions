class Solution {
public:
    int robRange(vector<int> &nums, int start, int end)
    {
        int next1=0;
        int next2=0;
        int curr;
        for(int i=end; i>=start; i--)
        {
            curr = max( nums[i]+next2, next1);
            next2 = next1;
            next1 = curr;
        }
        return next1;
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
