// leetcode problem : https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/?envType=daily-question&envId=2025-04-29


class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int maxE = *max_element(begin(nums), end(nums));        
            int n = nums.size();
            int i = 0, j = 0;        
            long long result = 0;
            int countMax = 0;        
            while(j < n) {
                if(nums[j] == maxE) {
                    countMax++;
                }            
                while(countMax >= k) {
                    // If we have at least k occurrences of maxE, count all subarrays ending at j
                    // The number of such subarrays is (n - j) because we can extend the subarray to the end of the array
                    result += n-j;                
                    if(nums[i] == maxE) {
                        countMax--;
                    }
                    i++;
                }
                j++;
            }        
            return result;
        }
    };



    /*
    Algorithm Explanation:
    1. Create a function `countSubarrays` that takes a vector of integers `nums` and an integer `k` as input.
    2. Find the maximum element `maxE` in the input array `nums` using `max_element` function.
    3. Initialize `n` to the size of the input array `nums`.
    4. Initialize two pointers `i` and `j` to 0, which will represent the start and end of the current subarray.
    5. Initialize `result` to 0, which will store the final count of valid subarrays.
    6. Initialize `countMax` to 0, which will count the occurrences of the maximum element in the current subarray.
    7. Use a while loop to iterate through the array `nums` with the pointer `j`:
        - If the current element `nums[j]` is equal to `maxE`, increment `countMax` by 1.
        - While the condition `countMax >= k` is satisfied, add `(n-j)` to `result`, which represents the number of valid subarrays ending at index `j`.
        - If the element at index `i` is equal to `maxE`, decrement `countMax` by 1.
        - Increment `i` by 1.
        - Increment `j` by 1.
    8. After the loop, return `result` as the final count of valid subarrays.
    9. The time complexity of this algorithm is O(n), where n is the size of the input array `nums`, as we are iterating through the array once.
    */