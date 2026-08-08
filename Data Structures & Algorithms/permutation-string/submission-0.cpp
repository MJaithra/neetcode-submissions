class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // fixed size window of size = s1.length();
        int k = s1.length();
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        for(int i=0; i<k; i++)
        {
            freq1[s1[i]-'a']++;
        }

        for(int right=0; right<s2.length(); right++)
        {
            freq2[s2[right]-'a']++;

            if(right >= k)
            {
                freq2[s2[right-k]-'a']--;
            }

            if(right >= k-1 && freq1 == freq2)
            {
                return true;
            }
        }

        return false;
    }
};
