class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        int i = 0;

        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }

        if (i == 0 || i == n - 1) return false;

        int j = i;

        while (j + 1 < n && nums[j] > nums[j + 1]) {
            j++;
        }

        if (j == i || j == n - 1) return false;

        while (j + 1 < n && nums[j] < nums[j + 1]) {
            j++;
        }

        return j == n - 1;
    }
};