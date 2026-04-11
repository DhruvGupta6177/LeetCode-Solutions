class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        int i = 0;
        int n = s.size();


        for(int j = 0;j < pattern.size(); j++){
            if(i >= n){
                return false;
            }

            string word = "";

            while(i < n && s[i]  != ' '){
                word += s[i];
                i++;
            }

            i++;

            char c = pattern[j];

            if(mp1.count(c) && mp1[c] != word){
                return false;
            }

            if (mp2.count(word) && mp2[word] != c) return false;

            mp1[c] = word;
            mp2[word] = c;

        }

        if(i < n){
            return false;
        }

        return true;
    }
};