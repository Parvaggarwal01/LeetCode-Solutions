class Solution {
public:
    int next(int n){
        int sum = 0;
        while(n>0){
            int rem=n%10;
            sum+=rem*rem;
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
       unordered_set<int> set;
       while(n != 1 && !set.count(n)){
        set.insert(n);
        n = next(n);
       }
       return n == 1;
    }
};