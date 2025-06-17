// leetcode problem : https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i=0,j=0;
        int max_length=0;
        int n=nums.size();
        multiset<int> st;
        while(j<n){
            st.insert(nums[j]);
            while (*st.rbegin() - *st.begin() > limit) {
                st.erase(st.find(nums[i]));
                i++;
            }

            max_length = max(max_length, j - i + 1);
            j++;
        }
        return max_length;
    }
};

/*
Algorithm Explanation:
1. Initialize two pointers `i` and `j` to represent the start and end of the sliding window.
2. Use a multiset `st` to maintain the current window of elements.
3. Iterate through the array with pointer `j`:
   - Insert the current element `nums[j]` into the multiset.
   - While the difference between the maximum and minimum elements in the multiset exceeds `limit`, remove the element at index `i` from the multiset and increment `i` to shrink the window from the left.
   - Update `max_length` with the maximum length of the valid subarray found so far.    
4. Return `max_length` as the result.
Time Complexity: O(n log n), where n is the size of the input array, due to the operations on the multiset.
Space Complexity: O(n), for storing the elements in the multiset.
*/


/*
Multiset data structure :
A multiset is a type of associative container in C++ that allows multiple occurrences of the same element. 
It is similar to a set, but unlike a set, which only allows unique elements, a multiset can store duplicate values.
It is implemented as a balanced binary search tree, which allows for efficient insertion, deletion, and search operations.
The multiset maintains the order of elements based on their values, and it provides logarithmic time complexity for insertion, deletion, and search operations.
*/