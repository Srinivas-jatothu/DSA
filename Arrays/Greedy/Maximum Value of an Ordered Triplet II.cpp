//leetcode problem : https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/description/?envType=daily-question&envId=2025-04-03

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            vector<int> leftMax(n);
            vector<int> rightMax(n);
    
            for (int i = 1; i < n; i++) {
                leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
            }
            for(int i = n-2; i >= 0; i--) {
                rightMax[i] = max(rightMax[i+1], nums[i+1]);
            }
            long long result = 0;
            for (int j = 1; j < n - 1; j++) {
                result = max(result, (long long)(leftMax[j] - nums[j]) * rightMax[j]);
            }
            return result;
        }
    };

    /*
        Algorithm explanation:
        1. The function `maximumTripletValue` is designed to find the maximum value of an ordered triplet `(i, j, k)` in the array `nums` such that:
        - `i < j < k`
        - The value is calculated as `(nums[i] - nums[j]) * nums[k]`.

        2. To optimize the solution:
        - Two auxiliary arrays, `leftMax` and `rightMax`, are used to store the maximum values to the left and right of each index `j` respectively.

        3. Steps:
        a. **Precompute leftMax**:
            - `leftMax[i]` stores the maximum value of `nums` from index `0` to `i-1`.
            - This is done using a single pass from left to right.

        b. **Precompute rightMax**:
            - `rightMax[i]` stores the maximum value of `nums` from index `i+1` to `n-1`.
            - This is done using a single pass from right to left.

        c. **Iterate through the array**:
            - For each index `j` (where `1 <= j <= n-2`), calculate the value of `(leftMax[j] - nums[j]) * rightMax[j]`.
            - Update the result with the maximum value encountered.

        4. **Return the result**:
        - The final result is the maximum value of the triplet `(i, j, k)` that satisfies the conditions.
    */

            