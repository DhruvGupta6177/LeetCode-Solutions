class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxwater = 0;
        int lp = 0;
        int rp = n-1;

        while(lp < rp){
            int wt = rp - lp;
            int ht = min(height[lp], height[rp]);
            int currwater = wt * ht;

            maxwater = max(maxwater, currwater);

            height[lp] < height[rp] ? lp++ : rp--;
        }

        return maxwater;
    }
};