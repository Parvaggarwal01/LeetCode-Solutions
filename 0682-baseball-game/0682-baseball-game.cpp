class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for(int i = 0; i<operations.size(); i++){
            if(operations[i] == "+"){
                int prev = s.top();
                s.pop();
                int prev2 = s.top();
                int sum = prev + prev2;
                s.push(prev);
                s.push(sum);
            }else if(operations[i] == "D"){
                int last = s.top();
                int ans = 2*last;
                s.push(ans);
            }else if(operations[i] == "C"){
                s.pop();
            }else{
                int p = stoi(operations[i]);
                s.push(p);
            }
        }
        int final = 0;
        while(!s.empty()){
            final = final + s.top();
            s.pop();
        }

        return final;
    }
};