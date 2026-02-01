class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int closest = nums[0] + nums[1] + nums[2];

        for(int i = 0; i <n-2;i++){
            int j = i+1;
            int k = n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if((sum - target) * (sum - target) < (closest - target) * (closest - target)){
                    closest = sum;
                }
                if(sum > target){
                    k--;
                }
                else if(sum < target){
                    j++;
                }
                else{
                    return sum;
                }
            }

        }

        return closest;


    }
};