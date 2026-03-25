class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int res = 0;
        int n = s.size();
        vector<int>count(3, 0);

        for(int r = 0; r < n; r++){
            count[s[r] - 'a']++;

            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                
                res += (n - r);
                count[s[l] - 'a']--;
                l++;
            }
        }

        return res;
    }
};