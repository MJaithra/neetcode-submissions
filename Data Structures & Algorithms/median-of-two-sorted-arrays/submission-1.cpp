class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if( nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size(), n = nums2.size();
        cout<<m<<" "<<n<<" --";
        int ls = (m + n + 1)/2;
        int left = 0, right = m;
        int i=0, j=0;

        while(left <= right)
        {
            i = left + (right - left)/2;
            j = ls - i;

            double aleft = (i==0)? INT_MIN : nums1[i-1];
            double aright = (i == m)? INT_MAX : nums1[i];

            double bleft = (j==0)? INT_MIN : nums2[j-1];
            double bright = (j == n)? INT_MAX : nums2[j];

            cout<< i <<" "<<j<<" "<<aleft<<" "<<aright<<" "<<bleft<<" "<<bright<<endl;

            if(aleft <= bright && bleft <= aright)
            {
                if((m+n) % 2 == 0)
                {
                    return (max(aleft,bleft) + min(aright,bright))/2;
                }
                else
                    return max(aleft, bleft);
            }
            else if (aleft > bright)
            {
                right = i-1;
            }
            else
                left = i+1;
        }

        return 0.0;
    }
};
