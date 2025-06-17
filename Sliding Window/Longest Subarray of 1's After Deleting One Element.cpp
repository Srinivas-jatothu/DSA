// leetcode problem : https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();

        int last_zero=-1;
        int res=0;
        int i=0,j=0;

        while(j<n){
            if(nums[j]==0){
                i=last_zero+1;
                last_zero=j;
            }
             res = max(res, j-i);
            j++;
        }
        return res;
    }
};



/*
Algorithm Explanation:
1. Initialize `n` as the size of the input vector `nums`, `last_zero` to -1 to keep track of the last index where a zero was found, and `res` to store the maximum length of the subarray found.
2. Use two pointers `i` and `j` to represent the current window in the array.
3. Iterate through the array with the `j` pointer:
   - If the current element `nums[j]` is zero, update `i` to be one position after the last zero found (`last_zero + 1`) and update `last_zero` to the current index `j`.
   - Calculate the length of the current subarray as `j - i` and update `res` with the maximum of its current value and this length.
   - Increment `j` to expand the window to the right.
4. After the loop, return `res`, which contains the length of the longest subarray of 1s after deleting one element (the zero).
Time Complexity: O(n), where n is the number of elements in the input vector `nums`.
This is because each element is processed at most once by the `j` pointer, and the `i` pointer only moves forward, ensuring that the algorithm runs in linear time.

*/