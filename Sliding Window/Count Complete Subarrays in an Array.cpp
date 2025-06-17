// leetcode problem : https://leetcode.com/problems/count-complete-subarrays-in-an-array/?envType=daily-question&envId=2025-04-24

class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
             int n = nums.size();
            unordered_set<int> st(begin(nums), end(nums));
            int c = st.size();
            int i = 0;
            int j = 0;
            int res = 0;
            unordered_map<int, int> mp;
            while(j < n) {
                mp[nums[j]]++;
                while(mp.size() == c) {
                    res += (n-j);
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0) {
                        mp.erase(nums[i]);
                    }
                    i++;
                }
                j++;
            }
            return res;
        }
    };

    /*
    Algorithm Explanation:
    1. Create a function `countCompleteSubarrays` that takes a vector of integers `nums` as input.
    2. Initialize `n` to the size of `nums`.
    3. Create an unordered set `st` to store unique elements from `nums`.
    4. Initialize `c` to the size of `st`, which represents the number of unique elements.
    5. Initialize two pointers `i` and `j` to 0, and a variable `res` to store the result.
    6. Create an unordered map `mp` to store the frequency of elements in the current window.
    7. Use a while loop to iterate through the array with the `j` pointer:
        - Increment the frequency of `nums[j]` in `mp`.
        - Use another while loop to check if the size of `mp` equals `c` (all unique elements are present):
            - Increment `res` by the number of remaining elements in the array (`n-j`).
            - Decrease the frequency of `nums[i]` in `mp`.
            - If the frequency becomes 0, erase it from `mp`.
            - Increment `i` to shrink the window from the left.
        - Increment `j` to expand the window from the right.
    8. Return `res` as the result.
    
    */