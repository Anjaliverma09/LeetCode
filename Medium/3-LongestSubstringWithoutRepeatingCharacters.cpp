class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n = s.length();
       unordered_map<char, int> freq;
       int left = 0; 
       int maxCount = 0;

       for(int right=0; right<n; right++){
            freq[s[right]]++;

            while(freq[s[right]] > 1){
                freq[s[left]]--;
                if(freq[s[left]] == 0) freq.erase(s[left]);
                left ++;
            }
            maxCount = max(maxCount, right - left +1);
       }
       return maxCount;
    }
};