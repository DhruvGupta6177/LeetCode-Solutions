class Solution {
public:
    void backtrack(string num, int target, int index,
                   long currValue, long prevValue,
                   string expression,
                   vector<string>& result) {
        
        if (index == num.size()) {
            if (currValue == target) {
                result.push_back(expression);
            }
            return;
        }

        for (int i = index; i < num.size(); i++) {
            
            
            if (i != index && num[index] == '0')
                break;

            string part = num.substr(index, i - index + 1);
            long number = stol(part);

            if (index == 0) {
                
                backtrack(num, target, i + 1,
                          number, number,
                          part, result);
            } else {
             
                backtrack(num, target, i + 1,
                          currValue + number,
                          number,
                          expression + "+" + part,
                          result);

              
                backtrack(num, target, i + 1,
                          currValue - number,
                          -number,
                          expression + "-" + part,
                          result);

              
                backtrack(num, target, i + 1,
                          currValue - prevValue + prevValue * number,
                          prevValue * number,
                          expression + "*" + part,
                          result);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> result;
        backtrack(num, target, 0, 0, 0, "", result);
        return result;
    }
};
