class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
            nums[2] = -nums[2]

            1 2 3 4 5
            1 3 4 2 2

            -1
              -4
                 -2
                    -3
                      +3  ---- 2 
        */
        int n = nums.size();
        int ret = -1;
        for(int i=0;i<n;i++)
        {
            int index = abs(nums[i]);
            if(nums[index]<0)
            {
                ret = index;
                break;
            }
            nums[index] = -nums[index];
        }
        return ret;
    }
};
