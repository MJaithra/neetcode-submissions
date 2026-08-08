class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHp;
        for(auto x :  stones)
        {
            maxHp.push(x);
        }

        while(maxHp.size() > 1)
        {
            int x = maxHp.top();maxHp.pop();
            int y = maxHp.top();maxHp.pop();

            if(abs(y-x) > 0)
                maxHp.push(abs(y-x));
        }

        return maxHp.size() == 1? maxHp.top() : 0;
    }
};
