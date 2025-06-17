// leetcode problem : https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0,j=0,count=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        while(j<n){
            mp[nums[j]]++;
            while(i<n && mp[nums[j]]>k){
                mp[nums[i]]--;
                i++;
            }

            count=max(count,j-i+1);
            j++;
        }
        return count;
    }
};


/*
Algorithm Explanation:
1. Initialize two pointers `i` and `j` to represent the start and end of the sliding window, respectively.
2. Use a hash map `mp` to keep track of the frequency of each number in the current window.
3. Iterate through the array with the `j` pointer:
   - Increment the frequency of `nums[j]` in the map.
   - If the frequency of `nums[j]` exceeds `k`, increment the `i` pointer to shrink the window from the left until the frequency is at most `k`.
   - Update the maximum length of the subarray found so far.
4. Return the maximum length of the subarray found.
Time Complexity: O(n), where n is the number of elements in the input array.

*/