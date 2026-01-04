class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int total = 0;
        for(int i = 0; i<nums.size(); i++){
            int count = 0;
            int sum = 0;
            for(int j = 1; j * j<=nums[i]; j++){
                if(nums[i]%j == 0){
                    int d1 = j;
                    int d2 = nums[i] / j;
                    if(d1 == d2){
                        count++;
                        sum += d1;
                    }else{
                        count += 2;
                        sum += d1 + d2;
                    }
                    if(count > 4){
                        break;
                    }
                }
            }
            if(count == 4){
                total = total + sum;
            }
        }
        return total;
    }
};