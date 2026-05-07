class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int>mask(n, 0);

        for(int i = 0;i < n; i++){
            for(char ch : words[i]){
                mask[i] |= (1 << (ch - 'a'));
            }
        }
        int ans = 0;

        for(int i = 0;i < n; i++){
            for(int j = i+1;j < n; j++){
                if((mask[i] & mask[j]) == 0){
                    int product = words[i].size() * words[j].size();
                    ans = max(ans, product);
                }
            }
        }
        return ans;
    }
};