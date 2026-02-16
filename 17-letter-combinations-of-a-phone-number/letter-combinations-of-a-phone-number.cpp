class Solution {
public:
    void helper(string digits, int in,string curr, string map[],vector<string> &ans){
        if(in == digits.size()){
            ans.push_back(curr);
            return ;
        }

        int digit = digits[in] - '0';
        string option = map[digit];
        for(int i = 0; i < option.size(); i++){
            helper(digits, in+1, curr+option[i], map,ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        string map[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        helper(digits, 0,"", map, ans);
        return ans;
    }
};