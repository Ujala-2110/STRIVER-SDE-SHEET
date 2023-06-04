class KthLargest {
public:
 
    priority_queue<int, vector<int> , greater<int>>pq;
    int K;

    KthLargest(int k, vector<int>& nums) {

        K = k;
        pq = priority_queue<int, vector<int> , greater<int>>();

        for(int i=0;i<nums.size();i++) {
            pq.push(nums[i]);

            if(pq.size() > k) pq.pop();
        }

    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size() > K) pq.pop();

        return pq.top();
    }
};