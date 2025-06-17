// leetcode problem : https://leetcode.com/problems/binary-subarrays-with-sum/description/


class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int i=0,j=0;
        int sum=0,prefix_zeros=0;
        int count=0;

        while(j<n){
            if(nums[j]==1){
                sum+=1;
            }
            while (i < j && (nums[i] == 0 || sum > goal)) {
                if (nums[i] == 1) {
                    prefix_zeros = 0;
                } else {
                    prefix_zeros += 1;
                }
                
                sum -= nums[i];
                i++;
            }


            if(sum==goal){
                count+=1+prefix_zeros;
            }          
            j++;
        }

        return count;
    }
};


/*
Algorithm Explanation:
1. Initialize `n` as the size of the input vector `nums`, and two pointers `i` and `j` to represent the current window in the array.
2. Initialize `sum` to keep track of the sum of the current window, `prefix_zeros` to count the number of consecutive zeros before the first one in the current window, and `count` to store the number of valid subarrays found.
3. Use a while loop to iterate through the array with the `j` pointer:
4. For each element at index `j`, check if it is 1:
   - If it is, increment `sum` by 1.
5. Use a while loop to shrink the window from the left with the `i` pointer:
   - If the element at index `i` is 0, increment `prefix_zeros` by 1.
   - If the element at index `i` is 1, reset `prefix_zeros` to 0.
   - Subtract the value of `nums[i]` from `sum` and increment `i` to move the left pointer forward.
6. If `sum` equals `goal`, it means we have found a valid subarray
    - Increment `count` by `1 + prefix_zeros`, which accounts for the number of valid subarrays ending at index `j` that can be formed by including the zeros before the first one in the current window.
7. Increment `j` to expand the window to the right.
8. After the loop, return `count`, which contains the total number of subarrays with a sum equal to `goal`.
Time Complexity: O(n), where n is the number of elements in the input vector `nums`. This is because each element is processed at most twice (once by `j` and once by `i`).
*/