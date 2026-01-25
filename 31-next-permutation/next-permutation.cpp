class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        int n = nums.size();
        // find the pivot
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        }

        if(pivot == -1){
            reverse(nums.begin(), nums.end()); // in-place changes
            return;
        }

        // 2nd step: 
        for(int i = n-1; i > pivot; i--){
            if(nums[i] > nums[pivot]){
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        //3rd step: reverse (piv+1 to n-1)
        int i = pivot + 1;
        int j = n-1;

        while(i <= j){
            swap(nums[i++], nums[j--]);
        }
    }
};