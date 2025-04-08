//leetcode problem : https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/description/?envType=daily-question&envId=2025-04-08


class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            int n = nums.size();
            unordered_set<int> st;
            for(int i = n-1; i >= 0; i--) {
                if(st.count(nums[i])) {
                    return ceil((i+1)/3.0);
                }
                st.insert(nums[i]);
            }
            return 0;
        }
    };


    /*
    Algorithm explanation:
    1. Initialize a variable `n` to the size of the input vector `nums`.
    2. Create an unordered set `st` to keep track of the unique elements encountered so far.
    3. Iterate through the elements of `nums` in reverse order (from the last element to the first).
    4. For each element `nums[i]`, check if it is already present in the set `st`.
    5. If it is present, it means we have found a duplicate element, and we can calculate the number of operations needed to make all elements distinct.
    6. The number of operations needed is the ceiling of `(i + 1) / 3.0`, which represents the number of elements that need to be removed to make the array distinct.
    7. If the element is not present in the set, add it to the set `st`.
    8. If no duplicates are found during the iteration, return 0, indicating that all elements are already distinct.
    9. The result is the minimum number of operations needed to make all elements in the array distinct.
    */
   