// leetcode problem : https://leetcode.com/problems/contains-duplicate-ii/description/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        unordered_set<int>st;

        while(j<n){
            if(abs(i-j)>k){
                st.erase(nums[i]);
                i++;
            }
            if(st.find(nums[j])!=st.end()){
                return true;
            }
            st.insert(nums[j]);
            j++;
        }
        
        return false;
    }
};


/*
Algorithm Explanation:
1. Initialize two pointers `i` and `j` to 0, and an unordered_set `st` to keep track of the elements in the current window.
2. Iterate through the array with the `j` pointer.
3. If the distance between `i` and `j` exceeds `k`, remove the element at index `i` from the set and increment `i`.
4. Check if the current element `nums[j]` is already in the set. If it is, return true.
5. If not, insert `nums[j]` into the set and increment `j`. 
6. If the loop completes without finding any duplicates within the specified distance, return false.
Time Complexity: O(n), where n is the number of elements in the array.

*/