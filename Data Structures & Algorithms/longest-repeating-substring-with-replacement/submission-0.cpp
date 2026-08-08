class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, ans = 0, maxFreq=0;
        vector<int> freq(26,0);
        for(int right=0; right<s.length(); right++)
        {
            maxFreq = max(maxFreq, ++freq[s[right] - 'A']);
            while((right-left+1) - maxFreq > k)
            {
                maxFreq = max(maxFreq, --freq[s[left] - 'A']);
                left++;
            }

            ans = max(ans, right-left+1);
        }

        return ans;
    }
};
