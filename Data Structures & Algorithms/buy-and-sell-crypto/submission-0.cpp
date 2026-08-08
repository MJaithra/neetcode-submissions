class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left =0, profit = 0;
        for(int right = 0; right < prices.size(); right++)
        {
            while(prices[left] > prices[right])
            {
                left ++;
            }
            
            profit = max(profit, prices[right] - prices[left]);
        }

        return profit;
    }
};
