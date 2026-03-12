class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
         int count[2] = {0, 0};
        
        for (int s : students) {
            count[s]++;
        }

        for (int s : sandwiches) {
            if (count[s] == 0) {
                return count[0] + count[1];
            }
            count[s]--;
        }

        return 0;
    }
};