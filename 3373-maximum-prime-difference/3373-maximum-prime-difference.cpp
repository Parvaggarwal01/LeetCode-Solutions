class Solution {
public:
    bool isPrime(int n) {
        // code here
        if(n <= 1){
            return false;
        }
        if(n <= 3){
            return true;
        }
        if(n%2==0 || n%3 ==0 ){
            return false;
        }
        for(int i = 5; i*i<=n; i+=6){
            if(n%i == 0 || n%(i+2) == 0){
                return false;
            }
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int firstIndex = 0;
        for(int i =0; i<nums.size(); i++){
            if(isPrime(nums[i])){
                firstIndex = i;
                break;
            }
        }
        int lastIndex = 0;
        for(int i =0; i<nums.size(); i++){
            if(isPrime(nums[i])){
                lastIndex = i;
            }
        }
        return lastIndex - firstIndex;
    }
};