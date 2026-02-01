class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       int n = nums.size();
       sort(nums.begin(), nums.end());
       vector<int> ans;

       for(int i = 0; i < n; ){
        if(i+1 < n && nums[i] == nums[i+1]){
            i += 2;
        }
        else{
            ans.push_back(nums[i]);
            i++;
        }
       }
       return ans;
    }
};