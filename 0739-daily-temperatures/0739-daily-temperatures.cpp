class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       stack <int>s;
       int n = temperatures.size();
       vector <int> res(n, 0);
       for(int i = 0; i<n; i++){
        while(!s.empty() && temperatures[i] > temperatures[s.top()]){
            int id = s.top();
            s.pop();
            res[id] = i - id;
        }
        s.push(i);
       } 
       return res;
    }
};