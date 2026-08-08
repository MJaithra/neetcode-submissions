class Solution {
public:
    int maxArea(vector<int>& heights) {
        int s = heights.size();
        int left = 0, right = s-1;
        int maxarea = 0;

        while(left < right)
        {
            maxarea = max(maxarea, min(heights[left], heights[right]) * (right-left));

            if(heights[left] < heights[right])
                left++;
            else
                right--;

        }

        return maxarea;
    }
};
