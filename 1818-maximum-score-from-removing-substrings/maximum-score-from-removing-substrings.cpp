class Solution {
public:
    int removeSubstring(string &s, string target, int score) {
        string temp;
        int points = 0;

        for(char c : s) {
            temp.push_back(c);

            int n = temp.size();
            if(n >= 2 && temp[n-2] == target[0] && temp[n-1] == target[1]) {
                temp.pop_back();
                temp.pop_back();
                points += score;
            }
        }

        s = temp;
        return points;
    }

    int maximumGain(string s, int x, int y) {
        int result = 0;

        if(x > y) {
            result += removeSubstring(s, "ab", x);
            result += removeSubstring(s, "ba", y);
        }
        else {
            result += removeSubstring(s, "ba", y);
            result += removeSubstring(s, "ab", x);
        }

        return result;
    }
};