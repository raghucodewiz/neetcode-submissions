class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> possibleHeight;

        int res = 0;
        for(int i=0;i<=heights.size();i++)
        {
            while(!possibleHeight.empty() && (i==heights.size() || heights[possibleHeight.top()] >= heights[i]))
            {
                int height = heights[possibleHeight.top()];
                possibleHeight.pop();
                int width = possibleHeight.empty() ? i : i - possibleHeight.top() - 1;

                res = max(res, height*width);
            }
            possibleHeight.push(i);
        }
        return res;
    }
};

