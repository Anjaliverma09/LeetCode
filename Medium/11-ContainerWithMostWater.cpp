class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int maxArea = 0;

        while(left < right){
            int totalHeight = min(height[left], height[right]); 
            int currentArea = totalHeight * (right - left);

            if(currentArea > maxArea) maxArea = currentArea;

            if(height[left] < height[right]) left++;
            else right--;    
        }   
        return maxArea;     
    }
};