class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();
        
        // Step 1: Compute prefix displacements
        vector<pair<int,int>> prefix(n+1, {0,0}); 
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i];
            if (s[i] == 'U') prefix[i+1].second++;
            if (s[i] == 'D') prefix[i+1].second--;
            if (s[i] == 'L') prefix[i+1].first--;
            if (s[i] == 'R') prefix[i+1].first++;
        }
        
        // Step 2: Compute suffix displacements
        vector<pair<int,int>> suffix(n+1, {0,0});
        for (int i = n-1; i >= 0; i--) {
            suffix[i] = suffix[i+1];
            if (s[i] == 'U') suffix[i].second++;
            if (s[i] == 'D') suffix[i].second--;
            if (s[i] == 'L') suffix[i].first--;
            if (s[i] == 'R') suffix[i].first++;
        }
        
        // Step 3: Try removing each substring of length k
        set<pair<int,int>> distinct;
        for (int i = 0; i + k <= n; i++) {
            int x = prefix[i].first + suffix[i+k].first;
            int y = prefix[i].second + suffix[i+k].second;
            distinct.insert({x, y});
        }
        
        return distinct.size();
    }
};
