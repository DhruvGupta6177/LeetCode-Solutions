class Solution {
public:
    int findMax(vector<int>& nums){
        int n = nums.size();
        int max = nums[0];
        for(int i = 0; i < n; i++){
            if(nums[i] > max){
                max = nums[i];
            }
        }
        return max;
    }


    int findSum(vector<int>& nums){
        int high = 0;
        for(int it : nums){
            high += it;
        }
        return high;
    }

    int findStudents(vector<int>& nums, int pages){
        int students = 1;
        int pagestudent = 0;
        for(int i = 0; i < nums.size(); i++){
            if(pagestudent + nums[i] <= pages){
                pagestudent += nums[i];
            }
            else{
                students += 1;
                pagestudent = nums[i];
            }
        }
        return students;
    }
    int findarray(vector<int>& nums, int n, int m){
        if(m > n){
            return -1;
        }
        int low = findMax(nums);
        int high = findSum(nums);

        while(low <= high){
            int mid  = (low + high)/2;
            int students = findStudents(nums, mid);
            if(students > m){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
    int splitArray(vector<int>& nums, int k) {
        return findarray(nums, nums.size(), k);
    }
};