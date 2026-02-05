class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>freq;
        for(char c : s){
            freq[c]++;
        }

        int n = s.size();

        vector<string> bucket(n+1);

        for(auto &it : freq) {
            bucket[it.second].append(it.second, it.first);
        }

        string ans = "";
        for(int i = n; i >= 1; i--){
            ans += bucket[i];
        }

        return ans;
    }
};