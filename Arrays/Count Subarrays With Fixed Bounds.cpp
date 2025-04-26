// LeetCode problem: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/?envType=daily-question&envId=2025-04-26


class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long answer = 0;
        int lastMinIndex = -1;
        int lastMaxIndex = -1;
        int lastIndexOutsideRange = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK) lastIndexOutsideRange = i;
            if (nums[i] == minK) lastMinIndex = i;
            if (nums[i] == maxK) lastMaxIndex = i;

            answer += max(0, min(lastMinIndex, lastMaxIndex) - lastIndexOutsideRange);
        }

        return answer;
    }
};


/*
Algorithm Explanation:
1. Create a function `countSubarrays` that takes a vector of integers `nums`, an integer `minK`, and an integer `maxK` as input.
2. Initialize `answer` to 0, which will store the final count of valid subarrays.
3. Initialize `lastMinIndex`, `lastMaxIndex`, and `lastIndexOutsideRange` to -1. These variables will keep track of the last indices of the minimum and maximum elements, and the last index outside the range [minK, maxK].
4. Use a for loop to iterate through the array `nums`:
    - If `nums[i]` is less than `minK` or greater than `maxK`, update `lastIndexOutsideRange` to `i`.
    - If `nums[i]` is equal to `minK`, update `lastMinIndex` to `i`.
    - If `nums[i]` is equal to `maxK`, update `lastMaxIndex` to `i`.
5. Calculate the number of valid subarrays ending at index `i` by taking the minimum of `lastMinIndex` and `lastMaxIndex`, and subtracting `lastIndexOutsideRange`. This gives the count of valid subarrays that can be formed with the current element as the end of the subarray.
6. Add the count of valid subarrays to `answer`.
7. Return `answer` as the final count of valid subarrays.
8. The time complexity of this algorithm is O(n), where n is the size of the input array `nums`, as we are iterating through the array once.
*/