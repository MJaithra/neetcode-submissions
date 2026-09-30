class Solution {
public:
// take it or skip it - trying botttom up directly
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1);
        dp[0]=0;
        for(int a = 1; a<=amount; a++)
        {
            int ans = 1e9;
            for(int i=0; i<n; i++)
            {
                if(coins[i] > a)
                    continue;

                int sub = dp[a-coins[i]];
                if(sub != 1e9)
                    ans=min(ans, 1+sub);
            }
            dp[a] = ans;
        }

        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};
