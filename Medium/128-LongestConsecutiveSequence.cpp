class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> sets(nums.begin(), nums.end());
        int length = 0;

        for(int i: sets){
            if(sets.find(i - 1) == sets.end()){
                int count = 1;

            while(sets.find(i + count) != sets.end())   count++;

            length = max(length, count);
            }
        }
        return length;
    }
};