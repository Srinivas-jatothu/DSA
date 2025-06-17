// leetcode problem : https://leetcode.com/problems/minimum-size-subarray-sum/description/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n= nums.size();
        int i=0,j=0;
        int sum=0;
        int min_len=INT_MAX;
        while(j<n){
            sum+=nums[j];

            while(sum>=target){
                sum-=nums[i];
                min_len=min(min_len,j-i+1);
                i++;
            }
            j++;
        }
        return min_len==INT_MAX ?  0 : min_len;
    }
};



/*
Algorithm Explanation:
1. Initialize `n` as the size of the input vector `nums`, and two pointers `i` and `j` to represent the current window in the array.
2. Initialize `sum` to keep track of the sum of the current window and `min_len` to store the minimum length of the subarray found, initialized to `INT_MAX`.
3. Use a while loop to iterate through the array with pointer `j`:
    - Add the current element `nums[j]` to `sum`.
    - While `sum` is greater than or equal to `target`, it means we have found a valid subarray:
        - Subtract the element at `nums[i]` from `sum` to shrink the window from the left.
        - Update `min_len` with the minimum of its current value and the length of the current window (`j - i + 1`).
        - Increment `i` to move the left pointer forward.
4. Increment `j` to expand the window to the right.
5. After the loop, check if `min_len` is still `INT_MAX`. If so, it means no valid subarray was found, and we return 0. Otherwise, return `min_len`, which is the length of the smallest subarray whose sum is at least `target`.
// 6. Time Complexity: O(n), where n is the number of elements in the input vector `nums`. This is because each element is processed at most twice (once by `j` and once by `i`).
*/