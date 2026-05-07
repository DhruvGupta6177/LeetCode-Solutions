class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();

        vector<int> idx(k, 0);
        vector<long long> ugly(n);
        ugly[0]=1;

        for(int i = 1;i < n; i++){
            long long nextugly = LLONG_MAX;

            for(int j = 0;j< k;j++){
                nextugly = min(nextugly, ugly[idx[j]] * primes[j]);
            }

            ugly[i] = nextugly;

            for(int j = 0;j < k; j++){
                if(ugly[idx[j]] * primes[j] == nextugly){
                    idx[j]++;
                }
            }
        }

        return ugly[n-1];
    }
};