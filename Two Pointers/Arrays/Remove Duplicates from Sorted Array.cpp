// leetcode problem : http://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        int i=0,j=i+1;
        
        while(j<n){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
            j++;
        }
                
        return i+1;
        
    }
};

/*
Algorithm Explanation:
1. Initialize two pointers: `i` at the start of the array and `j` at `i + 1`.
2. Use a while loop to iterate through the array with `j`:
   - If the element at `nums[i]` is not equal to `nums[j]`, increment `i` and set `nums[i]` to `nums[j]`.
   - Increment `j` to continue checking the next element.
3. Continue this process until `j` reaches the end of the array.
4. Return `i + 1`, which represents the new length of the array without duplicates 
   (the first `i + 1` elements of `nums` will be the unique elements).
// Time Complexity: O(n), where n is the length of the array, as we traverse the array once.
// Space Complexity: O(1), as we are modifying the array in place without using extra space
*/