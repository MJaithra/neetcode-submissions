class Solution {
public:
vector<vector<int>> res;
vector<int> curr;

    void backtrack(int start, int &rem, vector<int> &c)
    {
        if( rem == 0)
        {
            res.push_back(curr);
            return;
        }

        for( int i = start; i<c.size(); i++)
        {
            if(i>start && c[i] == c[i-1])
            {
                continue;
            }

            if(c[i] > rem)
                break;
            
            rem -= c[i];
            curr.push_back(c[i]);
            backtrack(i+1, rem, c);
            rem+= c[i];
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates);
        return res;
    }
};
