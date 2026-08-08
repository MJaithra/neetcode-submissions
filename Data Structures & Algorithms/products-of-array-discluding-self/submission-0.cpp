class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int s = nums.size();
        vector<int> prefixProd(s, 1);
        vector<int> suffixProd(s, 1);

        int prod=1;
        for(int i=1; i<s; i++)
        {
            prefixProd[i] = nums[i-1]*prefixProd[i-1];
        }
        for(int i=s-2; i >=0; i--)
        {
            suffixProd[i] = nums[i+1]*suffixProd[i+1];
        }

        for(int i=0; i<s; i++)
        {
            res.push_back(prefixProd[i]*suffixProd[i]);
        }

        return res;
    }
};
