class Solution {
public:
    int findMax(vector<int>& weights) {
        int n = weights.size();
        int max = weights[0];
        for (int i = 0; i < n; i++) {
            if (weights[i] > max) {
                max = weights[i];
            }
        }
        return max;
    }
    
    int findSum(vector<int> &weights){
        int high = 0;
        for(int it : weights){
            high += it;
        }
        return high;
    }

    int finddays(vector<int>& weights, int capacity) {
        int days = 1;
        int load = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (load + weights[i] > capacity) {
                days += 1;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = findMax(weights);
        int high = findSum(weights);

        while (low <= high) {
            int mid = (low + high) / 2;
            int noofdays = finddays(weights, mid);
            if (noofdays <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};