class Solution {
public:

    int quickselect(int l ,int r,int k,vector<int>& nums)
    {
        // [3 |2| 1| 5| 6| 4]

        int pivot = nums[r] , p = l;

        for(int i=l;i<r;i++)
        {
            if(nums[i] <= pivot) {
                swap(nums[i],nums[p]);
                p++;
            }
        }

        swap(nums[p],nums[r]);

        if(p > k) return quickselect(l,p-1,k,nums);
        else if(p < k) return quickselect(p+1,r,k,nums);
        else return nums[p];
    }

    int findKthLargest(vector<int>& nums, int k) {
        
        //Quickselect -> O(n)

        int n = nums.size();
        k = n - k;

        return quickselect(0,n-1,k,nums);
    }
};











