class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26, 0), count2(26, 0);

        if(s1.size() > s2.size()) return false;

        for(char i: s1)
            count1[i - 'a']++;
        
        int k = s1.length();
        for(int i=0; i<k; i++)
            count2[s2[i] - 'a']++;
        
        if(count1 == count2) return true;

        for(int i=k; i<s2.size(); i++){
            count2[s2[i] - 'a']++;
            count2[s2[i - k] - 'a']--;

            if(count1 == count2) return true;
        }
        return false;
    }
};