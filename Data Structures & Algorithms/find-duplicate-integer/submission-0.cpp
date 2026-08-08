class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0, fast=0;

        while(1)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if(slow == fast)
            {
                int start = 0;
                while(start != slow)
                {
                    start = nums[start];
                    slow = nums[slow];
                     if(start == slow)
                        return start;
                }
            }
        }

        return 0;
    }
};
