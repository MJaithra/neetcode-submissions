class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> leftSt;
        stack<pair<int,int>> rightSt;

        vector<int> leftMin;
        vector<int> rightMin(heights.size(), 0);

        int res = 0;
        int n = heights.size();

        for(int i=0; i< n; i++)
        {
            while(!leftSt.empty() && leftSt.top().first >= heights[i] )
            {
                leftSt.pop();
            }

            if(!leftSt.empty())
                leftMin.push_back(leftSt.top().second);
            else
                leftMin.push_back(-1);
            
            leftSt.push({heights[i], i});
        }

        for(int i = n-1; i >=0; i--)
        {
            while(!rightSt.empty() && rightSt.top().first >= heights[i])
                rightSt.pop();
            
            if(!rightSt.empty())
                rightMin[i] = rightSt.top().second;
            else
                rightMin[i] = n;
            
            rightSt.push({heights[i], i});
        }

        for(int i=0; i<n; i++)
        {
            // start = leftMin + 1, end = rightMin - 1, width = end-start+1;
            cout<<leftMin[i]<<" "<<rightMin[i]<<" "<<heights[i]<<endl;
            res=max(res, (rightMin[i] - leftMin[i] - 1) * heights[i]);
        }

        return res;
    }
};
