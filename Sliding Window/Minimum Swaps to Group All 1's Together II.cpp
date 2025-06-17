// leetcode problem : https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/


class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int countOnes = accumulate(begin(nums), end(nums), 0);
        int i = 0;
        int j = 0;
        int currCount = 0;
        int maxCount = 0;

        while(j < 2*n) {
            if(nums[j%n] == 1) {
                currCount++;
            }
            if(j-i+1 > countOnes) {
                currCount -= nums[i%n];
                i++;
            }
            maxCount = max(maxCount, currCount);
            j++;
        }
        return countOnes - maxCount;

    }
};



/*
Algorithm Explanation:
1. Count the total number of 1s in the array using `accumulate`.
2. Use a sliding window approach with two pointers `i` and `j`:
   - `i` represents the start of the window, and `j` represents the end of the window.
   - Iterate through the array twice (to handle circular nature) using `j`.
   - Count the number of 1s in the current window.
   - If the size of the window exceeds the total count of 1s, shrink the window from the left by incrementing `i`.
   - Update `maxCount` with the maximum number of 1s found in any valid window.
3. The minimum number of swaps required is the total count of 1s minus the maximum count of 1s found in any valid window.
Time Complexity: O(n), where n is the size of the input array.
*/