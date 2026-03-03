class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int sumL = 0, sumR = 0;
        int cntL = 0, cntR = 0;
        
        for(int i = 0; i < n; i++) {
            if(i < n/2) {
                if(num[i] == '?') cntL++;
                else sumL += num[i] - '0';
            } else {
                if(num[i] == '?') cntR++;
                else sumR += num[i] - '0';
            }
        }
        
        
        if((cntL + cntR) % 2 != 0)
            return true;
        
      
        int diff = sumL - sumR;
        int questionDiff = cntR - cntL;
        
        return diff != (questionDiff / 2) * 9;
    }
};