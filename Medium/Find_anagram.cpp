class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.length(), k = p.length();
        vector<int> countP(26, 0), countS(26, 0);

        for(char c: p)
            countP[c - 'a']++;
        
        for(int i=0; i<s.size(); i++){
            countS[s[i] - 'a']++;

        if(i >= p.size())
            countS[s[i - p.size()] - 'a']--;

        if(countS == countP)
            ans.push_back(i - p.size() + 1);
        }

        return ans;
    }
};