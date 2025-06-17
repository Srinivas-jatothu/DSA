// leetcode problem : https://leetcode.com/problems/subarrays-with-k-different-integers/description/

class Solution {
public:
    int slidingwindow(vector<int>& nums, int k){
        int i=0,j=0,count=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }

            count+=j-i+1;
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingwindow(nums,k)-slidingwindow(nums,k-1);
    }
};


/*
Algorithm Explanation:
1. Define a function `slidingwindow` that takes a vector of integers `nums` and an integer `k` as input.
2. Initialize two pointers `i` and `j` to 0, which will represent the start and end of the current subarray.
3. Initialize a variable `count` to 0, which will store the count of valid subarrays.
4. Get the size of the input array `nums` and store it in `n`.
5. Create an unordered map `mp` to keep track of the frequency of each number in the current subarray.
6. Use a while loop to iterate through the array `nums` with the pointer `j`:
   - Increment the frequency of `nums[j]` in the map.
   - While the size of the map exceeds `k`, decrement the frequency of `nums[i]` and check if it becomes zero. If it does, remove it from the map.
   - Increment the count by `(j - i + 1)`, which represents the number of valid subarrays ending at index `j`.
   - Increment `j` to expand the window.
7. Return the count of valid subarrays from the `slidingwindow` function.
8. In the `subarraysWithKDistinct` function, call the `slidingwindow` function twice:
   - First with `k` to get the count of subarrays with exactly `k` distinct integers.
   - Second with `k-1` to get the count of subarrays with at most `k-1` distinct integers.  
9. Subtract the result of the second call from the first call to get the count of subarrays with exactly `k` distinct integers.
10. Return the final count.
// Time Complexity: O(n), where n is the number of elements in the input array.
*/