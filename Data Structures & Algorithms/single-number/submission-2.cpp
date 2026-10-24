class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int result = 0;
        for(int num : nums)
        {
            result ^= num;
        }
        return result;
    }
};
