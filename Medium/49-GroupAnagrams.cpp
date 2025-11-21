class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;

        for(string i: strs){
            string key = i;
            sort(key.begin(), key.end());
            ans[key].push_back(i);
        }

        vector<vector<string>> result;
        for(auto i: ans)
            result.push_back(i.second);

        return result;
    }
};