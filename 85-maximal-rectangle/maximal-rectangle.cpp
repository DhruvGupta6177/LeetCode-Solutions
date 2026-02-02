class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0); // Sentinel to pop all at end
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxRect = 0;

        for (int i = 0; i < m; i++) {
            
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }

            
            maxRect = max(maxRect, largestRectangleArea(heights));
        }
        return maxRect;
    }
};