class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int n = heights.size();
        int r = n - 1;
        int maxArea = 0;

        while (l < r) {
            int width = r - l;
            int currentHeight = min(heights[l], heights[r]);
            maxArea = max(maxArea, width * currentHeight);

            if (heights[l] <= heights[r])
                l++;
            else
                r--;
        }
        return maxArea;
    }
};