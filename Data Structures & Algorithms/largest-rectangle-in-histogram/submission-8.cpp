class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> possibleHistograms;
        int maxArea = 0;

        for(int i =0;i<=n;i++)
        {
            int curHeight = (i==n) ? 0 : heights[i];

            while(!possibleHistograms.empty() && curHeight < heights[possibleHistograms.top()])
            {
                int h = heights[possibleHistograms.top()];
                possibleHistograms.pop();

                int lastBoundary = possibleHistograms.empty() ? -1 : possibleHistograms.top();
                int width = i -1 -lastBoundary;

                maxArea = max(maxArea, h * width);
            }
            possibleHistograms.push(i);
        }
        return maxArea;
    }
};
