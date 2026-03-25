class Solution {
public:
    int func(vector<int>& nums, int goal){
        if(goal < 0){
            return 0;
        }

        int l = 0;
        int r = 0;
        int sum = 0;
        int cnt = 0;

        while(r < nums.size()){
            sum = sum + (nums[r] % 2);

            while(sum > goal){
                sum =  sum - (nums[l] % 2);
                l = l + 1;
            }

            cnt = cnt + (r-l+1);
            r = r + 1;
        }
        return cnt;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums, k) - func(nums, k-1);
    }
};