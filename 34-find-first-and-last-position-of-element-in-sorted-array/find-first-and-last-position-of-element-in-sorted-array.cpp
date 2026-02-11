class Solution {
public:
    int firstoccur(vector<int> &nums, int n, int target){
        int st = 0;
        int end = n-1;
        int first = -1;
        while(st <= end){
            int mid = st + (end-st)/2;
            if(nums[mid] == target){
                first = mid;
                end = mid-1;
            }
            else if(nums[mid] > target){
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return first;
    }

    int lastoccur(vector<int> &nums, int n, int target){
        int st = 0;
        int end = n-1;
        int last = -1;
        while(st <= end){
            int mid = st + (end- st)/2;
            if(nums[mid] == target){
                last = mid;
                st  = mid  + 1;
            }
            else if(nums[mid] > target){
                end  = mid  - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = firstoccur(nums, n, target);
        if(first == -1){
            return {-1,-1};
        }
        int last = lastoccur(nums, n, target);
        return {first, last};
    }
};