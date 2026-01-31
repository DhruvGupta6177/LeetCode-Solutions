class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;            //SC = O(UniqueGroups)
        int n = nums.size();

        sort(nums.begin(), nums.end());         // TC = O(nLog(n))

        for(int i = 0; i < n; i++){             // TC = O(n)
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i+1; j < n; ){          //TC = O(n)
                int p = j+1, q = n-1;

                while(p < q){                   // TC = O(n)
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + (long long)nums[q];

                    if(sum < target){
                        p++;
                    }
                    else if(sum > target){
                        q--;
                    }
                    else{
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++; q--;

                        while(p < q && nums[p] == nums[p-1]){
                            p++;
                        }
                    }

                    
                }


                j++;
                
                while(j < n && nums[j] == nums[j-1]){
                    j++;
                }
                
                
            }
        }
        return ans;
    }
};