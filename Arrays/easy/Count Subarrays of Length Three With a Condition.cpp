// leetcode problem : https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/description/?envType=daily-question&envId=2025-04-27

class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int n = nums.size();
            int result = 0;
            for(int i = 1; i < n-1; i++) {
                if(nums[i] == (nums[i-1] + nums[i+1])*2) {
                    result++;
                }
            }
            return result;
        }
    };




    /*
    Algorithm Explanation:
    1. Create a function `countSubarrays` that takes a vector of integers `nums` as input.
    2. Initialize `n` to the size of the input array `nums`.
    3. Initialize `result` to 0, which will store the final count of valid subarrays.
    4. Use a for loop to iterate through the array `nums` starting from index 1 and ending at index `n-2` (inclusive):
        - Check if the current element `nums[i]` is equal to the average of its two neighbors, i.e., `(nums[i-1] + nums[i+1]) * 2`.
        - If the condition is satisfied, increment `result` by 1.
    5. After the loop, return `result` as the final count of valid subarrays.
    6. The time complexity of this algorithm is O(n), where n is the size of the input array `nums`, as we are iterating through the array once.
    7. The space complexity is O(1) since we are using a constant amount of extra space.    
    */