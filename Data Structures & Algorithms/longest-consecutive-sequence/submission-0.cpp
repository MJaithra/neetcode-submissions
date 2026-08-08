class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLen = 0, len = 0;

        for(auto n : numSet)
        {
            len = 0;
            if(!numSet.count(n-1))
            {
                while(numSet.count(n))
                {
                    len++;
                    maxLen = max(maxLen, len);
                    n++;
                }
            }
        }

        return maxLen;
    }
};
