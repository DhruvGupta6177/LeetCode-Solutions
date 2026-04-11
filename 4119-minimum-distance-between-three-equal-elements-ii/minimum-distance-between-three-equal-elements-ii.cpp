class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, pair<int, int>> mp;
        int ans = INT_MAX;


        for(int i = 0;i < nums.size(); i++){
            int val = nums[i];

            if(mp.count(val) && mp[val].second != -1){
                int first = mp[val].first;
                ans = min(ans, i-first);
            }


            if(!mp.count(val)){
                mp[val] = {i, -1};
            }
            else if(mp[val].second == -1){
                mp[val].second = i;
            }
            else{
                mp[val] = {mp[val].second, i};
            }
        }

        return ans == INT_MAX ? -1 : 2*ans;
    }
};