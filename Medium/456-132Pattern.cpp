class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3) return false;

        stack<pair<int, int>> st;
        int curr_min = nums[0];

        for(int i=1; i<nums.size(); i++){
            int n = nums[i];
            while(!st.empty() && n >= st.top().first) st.pop();

            if(!st.empty() && n > st.top().second)
                return true;

            st.push({n, curr_min});

            curr_min = min(curr_min, n);
        }
        return false;
    }
};