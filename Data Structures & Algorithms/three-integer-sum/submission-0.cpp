#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 1. Sort the array in ascending order so we can use two pointers 
        //    and easily skip duplicate values next to each other.
        std::sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        int n = nums.size();
        // Removed unused `vector<int> ans;`

        for (int i = 0; i < n; i++) {
            // OPTIMIZATION: Since the array is sorted, if the first number is > 0,
            // no two numbers after it can sum with it to 0.
            if (nums[i] > 0) break;

            // FIX (Duplicates): Skip duplicate values for the first element (nums[i])
            // so we don't start the same search twice.
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int ele1 = nums[i];
            // FIX (Syntax): Replaced `-1.0ele1` with `-ele1` (since ele1 + nums[j] + nums[k] == 0)
            int target = -ele1; 

            int j = i + 1; // Left pointer
            int k = n - 1; // Right pointer

            while (j < k) {
                int sum = nums[j] + nums[k];

                // FIX (Pointer Direction): If sum is too large, decrease the right pointer (k--)
                if (sum > target) {
                    k--;
                }
                // FIX (Bracket Typo & Pointer Direction): Fixed `nums[j + nums[k] < target]`
                // If sum is too small, increase the left pointer (j++)
                else if (sum < target) {
                    j++;
                }
                // Found a valid triplet: nums[i] + nums[j] + nums[k] == 0
                else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // FIX (Duplicates): Skip duplicate values for the second and third elements
                    // so we only record unique triplets.
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        
        // FIX (Return Value): Return `res` instead of an empty `{}` vector
        return res;
    }
};