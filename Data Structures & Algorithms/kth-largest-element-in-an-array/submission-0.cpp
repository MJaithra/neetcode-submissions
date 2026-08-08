class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHp;
        for(int i=0; i< nums.size(); i++)
        {
            minHp.push(nums[i]);
            if(minHp.size() > k)
                minHp.pop();
        }

        return minHp.top();
    }
};
