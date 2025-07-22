class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> first;
        vector<int> second;
        for(int i =0; i<edges.size(); i++){
            first.push_back(edges[i][0]);
            second.push_back(edges[i][1]);
        }
        for(int i = 0; i<edges.size(); i++){
            for(int j = 0; j<edges.size(); j++){
                if(first[i] == second[j]){
                    return first[i];
                }else if(second[i] == second[i+1]){
                    return second[i];
                }else if(first[i] == first[i+1]){
                    return first[i];
                }
            }
        }
        return -1;
    }
};