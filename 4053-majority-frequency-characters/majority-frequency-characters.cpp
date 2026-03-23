class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char, int> freq;

        // Step 1: Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Group characters by frequency
        unordered_map<int, vector<char>> groups;
        for (auto& p : freq) {
            groups[p.second].push_back(p.first);
        }

        // Step 3: Find the best group
        int bestSize = 0;
        int bestFreq = 0;
        vector<char> bestGroup;

        for (auto& p : groups) {
            int f = p.first;
            int sz = p.second.size();
            if (sz > bestSize || (sz == bestSize && f > bestFreq)) {
                bestSize = sz;
                bestFreq = f;
                bestGroup = p.second;
            }
        }

        // Step 4: Build result string
        string ans;
        for (char c : bestGroup) ans.push_back(c);

        return ans;
    }
};
