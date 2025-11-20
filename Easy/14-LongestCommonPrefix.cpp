class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        sort(strs.begin(), strs.end());

        string result = "";
        string first = strs[0], last = strs[strs.size()-1];
        for(int i=0; i<first.size(); i++){
            if(first[i] != last[i]) break;
            result += first[i];
        }
        return result;
    }
};