class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int leftMax = values[0] + 0;
        int ans = 0;

        for(int j=1; j<n; j++){
           int rightMax = values[j] - j;
           ans = max(ans, leftMax + rightMax);
           leftMax = max(leftMax, values[j] + j);
        }
        return ans;
    }
};