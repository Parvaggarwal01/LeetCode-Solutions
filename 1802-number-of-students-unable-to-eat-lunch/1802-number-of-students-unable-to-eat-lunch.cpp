class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q1;
        queue<int> q2;

        for(int st: students){
            q1.push(st);
        }
        for(int sa: sandwiches){
            q2.push(sa);
        }

        int count = 0;
        while(!q1.empty()){
            if(q1.front() == q2.front()){
                q1.pop();
                q2.pop();
                count = 0;
            }else{
                q1.push(q1.front());
                q1.pop();
                count++;

                if(count == q1.size()){
                    break;
                }
            }
        }

        return q1.size();
    }
};