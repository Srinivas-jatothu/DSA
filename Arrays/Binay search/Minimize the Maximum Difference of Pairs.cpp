// leetcode problem: https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/?envType=daily-question&envId=2025-06-13https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/?envType=daily-question&envId=2025-06-13

class Solution {
public:
    int n;
    
    bool isValid(vector<int>& nums, int mid, int p) {
        
        int i = 0;
        int pairs = 0;
        while(i < n-1) {
            
            if(nums[i+1] - nums[i] <= mid) {
                pairs++;
                i+=2;
            } else {
                i++;
            }
        }
        
        return pairs >= p;
        
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        n = nums.size();
        
        sort(begin(nums), end(nums));
        
        int l = 0;
        int r = nums[n-1] - nums[0];
        
        int result = INT_MAX;
        
        while(l <= r) {
            
            int mid = l + (r-l)/2;
            
            if(isValid(nums, mid, p)) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
            
        }
        
        return result;
        
    }
};





/*
Algorithm Explanation:
1. Define a function `isValid` that checks if it is possible to form at least `p` pairs with a maximum difference of `mid`.
2. In `isValid`, iterate through the sorted array and count how many pairs can be formed without exceeding the difference `mid`.
3. In the main function `minimizeMax`, sort the input array `nums`.
4. Initialize binary search bounds: `l` as 0 and `r` as the difference between the maximum and minimum elements in `nums`.
5. Perform binary search:
   - Calculate the middle point `mid`.
   - Use `isValid` to check if at least `p` pairs can be formed with the current `mid`.
   - If valid, update the result and move the right bound down; otherwise, move the left bound up.
6. Return the minimum maximum difference found.
7. The time complexity of this solution is O(n log(max_diff)), where n is the number of elements in the array and max_diff is the maximum difference between any two elements.

*/