class KthLargest {
public:
    int cap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    KthLargest(int k, vector<int>& nums) {
        cap = k;
        for(int i=0; i< nums.size(); i++)
        {
            minHeap.push(nums[i]);
            if(minHeap.size() > k)
                minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > cap)
            minHeap.pop();
        
        return minHeap.top();
    }
};
