class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> st;
        int n = height.size();

        for(int i = 0; i<n; i++){
            while(!st.empty() && height[i] > height[st.top()]){
                int bottom = st.top();
                st.pop();

                if(st.empty()){
                    break;
                }

                int left = st.top();
                int right = i;

                int width = right - left - 1;
                int h = min(height[left], height[right]) - height[bottom];

                ans += width * h;
            }

            st.push(i);
        }
        return ans;
    }
};