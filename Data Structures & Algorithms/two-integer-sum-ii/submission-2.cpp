class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int right = numbers.size()-1;
        int left = 0;

        while(left < right)
        {
            if((numbers[right]+numbers[left])<target){
                left++;
            }
            else if((numbers[left]+numbers[right])>target)
            {
                right--;
            }
            else if((numbers[left]+numbers[right]) == target)
            {
                return {left+1, right+1};
            }
        }
        return {-1, -1};
    }
};
