class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> tempStack;


        for(int i=0;i<temperatures.size();i++)
        {
            int currentTemprature = temperatures[i];
            while(!tempStack.empty() && currentTemprature > temperatures[tempStack.top()])
            {
                int index = tempStack.top();
                res[index] = i - index;
                tempStack.pop();
            }
            tempStack.push(i);
        }
        return res;
    }
};
/*
[30,38,30,36,35,40,28]

1 - 38
38 > 30


res - 0 - 1 -0
res - 2 - 3 - 2 - 
tempStack - 1 3

*/
