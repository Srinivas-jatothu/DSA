// leetcode problem : https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description/?envType=daily-question&envId=2025-04-28


class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            int n = nums.size();       
            long long result = 0;
            long long sum    = 0;
            int i = 0;
            int j = 0;
            while(j < n) {
                sum += nums[j];
                while(i <= j && sum * (j - i + 1) >= k) { 
                    sum -= nums[i];
                    i++;
                }
                result += (j-i+1);
                j++;
            }
            return result;
        }
    };


    /*
    Algorithm Explanation:
    1. Create a function `countSubarrays` that takes a vector of integers `nums` and a long long integer `k` as input.
    2. Initialize `n` to the size of the input array `nums`.
    3. Initialize `result` to 0, which will store the final count of valid subarrays.
    4. Initialize `sum` to 0, which will store the sum of the current subarray.
    5. Initialize two pointers `i` and `j` to 0, which will represent the start and end of the current subarray.
    6. Use a while loop to iterate through the array `nums` with the pointer `j`:
        - Add the current element `nums[j]` to `sum`.
        - While the condition `i <= j && sum * (j - i + 1) >= k` is satisfied, subtract `nums[i]` from `sum` and increment `i` by 1.
        - Add `(j-i+1)` to `result`, which represents the number of valid subarrays ending at index `j`.
        - Increment `j` by 1.
    7. After the loop, return `result` as the final count of valid subarrays.
    8. The time complexity of this algorithm is O(n), where n is the size of the input array `nums`, as we are iterating through the array once.
    */