class Solution {
public:
    int clumsy(int n) {
      stack<int> st;
        st.push(n);
        n--;

        int op = 0;

        while(n > 0) {

            if(op % 4 == 0) {            // *
                int top = st.top(); 
                st.pop();
                st.push(top * n);
            }

            else if(op % 4 == 1) {       // /
                int top = st.top();
                st.pop();
                st.push(top / n);
            }

            else if(op % 4 == 2) {       // +
                st.push(n);
            }

            else {                       // -
                st.push(-n);
            }

            op++;
            n--;
        }

        int result = 0;

        while(!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;  
    }
};