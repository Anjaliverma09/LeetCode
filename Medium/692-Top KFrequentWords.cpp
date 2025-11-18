class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(string i: words)
            mp[i]++;

        priority_queue<pair<int, string>> pq;
        for(auto i: mp){
            pq.push({-i.second, i.first});
            if(pq.size() > k) pq.pop();
        }

        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};