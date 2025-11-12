class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;

        for(int i=0; i<nums2.size(); i++){
            while(!st.empty() && nums2[i] > st.top()){
                int topEle = st.top();
                st.pop();
                mp[topEle] = nums2[i];
            }
            st.push(nums2[i]);
        }
        while(!st.empty()){
            mp[st.top()] = -1;
            st.pop();
        }
        vector<int> ans;
        for(int num: nums1){
            ans.push_back(mp[num]);
        }
        return ans;
    }
};