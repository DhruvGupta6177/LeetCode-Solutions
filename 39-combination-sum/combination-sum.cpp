class Solution {
public:

    set<vector<int>> s;
    void getAllCombinations(vector<int>& arr, int idx, int target, vector<int> &combin, vector<vector<int>> &ans){
        if(idx == arr.size() || target < 0){
            return;
        }

        if(target == 0){
            if(s.find(combin) == s.end()){
                ans.push_back(combin);
                s.insert(combin);
            }
            
            return ;
        }

        combin.push_back(arr[idx]);

        //single
        getAllCombinations(arr, idx+1, target - arr[idx], combin, ans);
        //multiple
        getAllCombinations(arr, idx, target - arr[idx], combin, ans);

        combin.pop_back();

        //exclude
        getAllCombinations(arr, idx+1, target, combin, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int> combin;
        vector<vector<int>> ans;

        getAllCombinations(arr, 0, target, combin, ans);

        return ans;
    }
};