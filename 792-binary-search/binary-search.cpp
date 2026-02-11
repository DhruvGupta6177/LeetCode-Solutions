class Solution {
public:
    int binsearch(vector<int>& nums, int target, int st, int end) {
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                return binsearch(nums, target, st, mid - 1);
            } else {
                return binsearch(nums, target, mid + 1, end);
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return binsearch(nums, target, 0, nums.size() - 1);
    }
};