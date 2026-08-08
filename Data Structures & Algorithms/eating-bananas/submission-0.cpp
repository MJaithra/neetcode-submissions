class Solution {
public:
    bool canDo(int k, vector<int>& p, int h)
    {
        long long ans = 0;
        for(int i=0; i < p.size(); i++)
        {
            int hours = (p[i] + k -1)/k;
            ans = ans + hours;
            if(ans > h)
                return false;
        }

        return true;;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left =1, right = *max_element(piles.begin(), piles.end());
        int ans = right;
        while(left<=right)
        {
            int mid = left + (right-left)/2;

            if(canDo(mid, piles, h))
            {
                ans = mid;
                right = mid -1;
            }
            else
                left = mid+1;
        }

        return ans;
    }
};
