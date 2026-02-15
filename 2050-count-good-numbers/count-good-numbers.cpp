class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long base, long long exp){
        long long result = 1;
        while(exp > 0){
            if(exp % 2 == 1){
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }
    
    int countGoodNumbers(long long n) {
      long long evencount = (n + 1)/2;
      long long oddcount = n / 2;

      long long evenpart = power(5, evencount);
      long long oddpart = power(4, oddcount);

      return (oddpart * evenpart) % MOD;  
    }
};