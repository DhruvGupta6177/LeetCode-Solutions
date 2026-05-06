class Solution {
public:
    long long toNum(string s){
        long long num = 0;
        for(char ch : s){
            num = num * 10 + (ch - '0');
        }
        return num;
    }

    bool check(string num,long long a, long long b, int start){
        while(start < num.size()){
            long long sum = a + b;
            string s = to_string(sum);

            if(num.substr(start, s.size()) != s){
                return false;  
            }

            start += s.size();
            a = b;
            b = sum;
        }
        return true;
    }
    bool isAdditiveNumber(string num) {
        int n = num.size();

        for(int i = 1;i <= n/2; i++){
            for(int j = 1; max(i,j) <= n-i-j;j++){
                string s1 = num.substr(0,i);
                string s2 = num.substr(i,j);

                if((s1.size() > 1 && s1[0] == '0') || (s2.size() > 1 && s2[0] == '0')){
                    continue;
                }

                long long a = toNum(s1);
                long long b = toNum(s2);

                if(check(num, a, b, i+j)){
                    return true;
                }
            }
        }
        return false;
    }
};