class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n = nums.size();
        // for(int i = 0; i<=n; i++){
        //     bool found = false;
        //     for(int j = 0; j<n; j++){
        //         if(nums[j] == i){
        //             found = true;
        //             break;
        //         }
        //     }
        //     if(!found){
        //         return i;
        //     }
        // }
        // return -1;

        // int n = nums.size();
        // int asum = n * (n + 1) / 2;
        // int bsum = 0;
        // for(int i = 0; i < n; i++){
        //     bsum += nums[i];
        // }

        // return asum - bsum;

        // int n = nums.size();
        // vector <int> hash(n+1, 0);
        // for(int i = 0; i<n; i++){
        //     hash[nums[i]] = 1;
        // }

        // for(int i = 1; i<=n; i++){
        //     if(hash[i] == 0){
        //         return i;
        //     }
        // }
        // return 0;

        int n = nums.size();
        int xor1 = 0;
        int xor2 = 0;
        for(int i = 0; i<n; i++){
            xor2 = xor2 ^ nums[i];
            xor1 = xor1 ^ i;
        }
        xor1 = xor1 ^ n;

        return xor1 ^ xor2;
    }
};