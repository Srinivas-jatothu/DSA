// leetcode problem : https://leetcode.com/problems/count-of-interesting-subarrays/description/?envType=daily-question&envId=2025-04-25


class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
            int n = nums.size();
    
            unordered_map<int, long long> mp; //remainder -> count
            long long sum = 0; //sum will be equal to cnt of those elements % m == k
    
            long long result = 0;
    
            mp[0] = 1;
            for(int i = 0; i < n; i++) {
                if(nums[i] % m == k)
                    sum += 1;
    
                int r1 = sum%m;
    
                int r2 = (r1 - k + m) % m;
    
                result += mp[r2];
                mp[r1]++;
            }
    
            return result;
    
        }
    };



    /*
    Algorithm Explanation:
    1. Create a function `countInterestingSubarrays` that takes a vector of integers `nums`, an integer `m`, and an integer `k` as input.
    2. Initialize `n` to the size of `nums`.
    3. Create an unordered map `mp` to store the count of remainders.
    4. Initialize `sum` to 0, which will count the number of elements in `nums` that are congruent to `k` modulo `m`.
    5. Initialize `result` to 0, which will store the final count of interesting subarrays.
    6. Set `mp[0]` to 1, as there is one way to have a sum of 0.
    7. Use a for loop to iterate through the array `nums`:
        - If `nums[i] % m == k`, increment `sum` by 1.
        - Calculate `r1` as `sum % m`.
        - Calculate `r2` as `(r1 - k + m) % m`, which represents the required remainder.
        - Increment `result` by the count of subarrays with remainder `r2` in `mp`.
        - Increment the count of remainder `r1` in `mp`.
    8. Return `result` as the final count of interesting subarrays.
    9. The time complexity of this algorithm is O(n), where n is the size of the input array `nums`, as we are iterating through the array once and using a hash map for constant time lookups.
    */