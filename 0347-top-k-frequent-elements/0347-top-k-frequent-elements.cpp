class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        // Min-heap to keep track of top k elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto it = mp.begin(); it != mp.end(); it++) {
            pq.push({it->second, it->first});  // {frequency, number}
            if (pq.size() > k) {
                pq.pop();  // remove the element with lowest frequency
            }
        }

        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
