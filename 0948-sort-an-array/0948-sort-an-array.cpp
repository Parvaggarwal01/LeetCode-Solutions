class Solution {
public:
    int partition(vector<int>& arr, int s, int e){
        int randomIndex = s + rand() % (e - s + 1);
        swap(arr[randomIndex], arr[e]);
        int pivot = arr[e]; 
        int i = s-1;
        for(int j = s; j<e; j++){
            if(arr[j] < pivot){
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i+1], arr[e]);
        return i+1;
    }
    void quickSort(vector<int>& arr, int s, int e){
        if(s >= e){
            return;
        }
        long long int pivot = partition(arr, s, e);
        quickSort(arr, s, pivot-1);
        quickSort(arr, pivot+1, e);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quickSort(nums, 0, n-1);
        return nums;
    }
};