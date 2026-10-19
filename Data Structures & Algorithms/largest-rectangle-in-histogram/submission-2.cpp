#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int n = heights.size();
        std::stack<int> st; // Monotonically increasing stack of indices
        int maxArea = 0;

        // Iterate up to n (inclusive) using 0 as a sentinel height at i == n
        for (int i = 0; i <= n; ++i) {
            int currHeight = (i == n) ? 0 : heights[i];

            // When current bar is strictly smaller than the bar at st.top(),
            // st.top() has found its right boundary (i) and left boundary (new st.top()).
            while (!st.empty() && currHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                // If stack is empty, no smaller bar exists to the left (width spans 0 to i - 1)
                int leftBoundary = st.empty() ? -1 : st.top();
                int width = i - leftBoundary - 1;

                maxArea = std::max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};