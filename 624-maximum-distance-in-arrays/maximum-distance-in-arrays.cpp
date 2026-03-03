class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
       int globalMin = arrays[0][0];
        int globalMax = arrays[0].back();
        int result = 0;
        
        for(int i = 1; i < arrays.size(); i++) {
            int currentMin = arrays[i][0];
            int currentMax = arrays[i].back();
            
            result = max(result, max(abs(currentMax - globalMin), 
                                     abs(globalMax - currentMin)));
            
            globalMin = min(globalMin, currentMin);
            globalMax = max(globalMax, currentMax);
        }
        
        return result; 
    }
};