class Solution {
public:
    int findPivot(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(mid > 0 && nums[mid] < nums[mid - 1])
                return nums[mid];
            
            if(mid < n - 1 && nums[mid] > nums[mid + 1])
                return nums[mid + 1];

            if(nums[left] <= nums[mid]) 
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return nums[0];
    }
    
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;

        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right])
                left = mid + 1;
            
            else
                right = mid;
        }
        return nums[left];
    }
};
