class Solution {
public:
    int sumByD(vector<int> &arr, int div){
        int sum = 0;
        int n = arr.size();
        for(int i = 0;i < n;i++){
            sum = sum + ceil((double)(arr[i]) / (double)(div));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& arr, int threshold) {
        int low = 1;
        int high = arr[0];
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > high){
                high = arr[i];
            }
        }
        
        while(low <= high){
            int mid = (low + high) / 2;
            if(sumByD(arr, mid) <= threshold){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
        }
};