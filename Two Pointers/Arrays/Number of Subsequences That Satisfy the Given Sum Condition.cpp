// leetcode problem : https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/?envType=daily-question&envId=2025-06-29


class Solution {
public:
    int M = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        
        //1. Sort
        sort(begin(nums), end(nums));
        
        vector<int> power(n);
        power[0] = 1;
        
        for(int i = 1; i<n; i++) {
            power[i] = (power[i-1] * 2) % M;
        }   
        
        //2. l = 0, r = n-1
        int l = 0, r = n-1;
        int result = 0;
        while(l <= r) {
            
            if(nums[l] + nums[r] <= target) {
                int diff = r-l;
                result = (result % M + power[diff]) % M;
                l++;
            } else {
                r--;
            }
            
        }
        
        return result;
    }
};


/*
Algorithm Explanation:
1. The function `numSubseq` takes a vector of integers `nums` and an integer `target` as input.
2. It first sorts the `nums` vector in ascending order. 
3. It initializes a vector `power` to store powers of 2, where `power[i]` represents \(2^i \mod M\) (with \(M = 10^9 + 7\)). Because the number of subsequences can be large, we use modulo \(M\) to prevent overflow.
4. It calculates the powers of 2 for all indices from 0 to \(n-1\) and stores them in the `power` vector.
5. It initializes two pointers, `l` (left) at the start of the array and `r` (right) at the end of the array.
6. It enters a while loop that continues until `l` is less than or equal to `r`.
7. Inside the loop, it checks if the sum of the elements at the left and right pointers (`nums[l] + nums[r]`) is less than or equal to the `target`.
8. If the condition is satisfied, it calculates the number of valid subsequences that can be formed with the current left and right pointers. The number of valid subsequences is given by \(2^{(r - l)}\) (the number of ways to choose elements between `l` and `r`), and it adds this value to the result, taking modulo \(M\).
9. It then increments the left pointer (`l++`) to consider the next element.
10. If the condition is not satisfied, it decrements the right pointer (`r--`) to consider a smaller element.
11. Finally, it returns the result, which is the total number of valid subsequences that satisfy the given sum condition.
Time Complexity: O(n log n) due to sorting, and O(n) for the two-pointer traversal, resulting in an overall time complexity of O(n log n).
Space Complexity: O(n) for the `power` vector.
*/