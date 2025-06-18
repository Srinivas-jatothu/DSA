// leetcode problem : https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/?envType=daily-question&envId=2025-06-18

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n =nums.size();
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i+=3){
            if(nums[i+2]-nums[i]>k){
                return {} ;
            }
            res.push_back({nums[i],nums[i+1],nums[i+2]});
        }
        return res;
    }
};


/*
Algorithm Explanation:
1. **Sorting**: First, sort the input array `nums` to ensure that the elements are in non-decreasing order. This allows us to easily check the maximum difference between the smallest and largest elements in each group of three.
2. **Grouping**: Iterate through the sorted array in steps of three. For each group of three elements, check if the difference between the largest and smallest element in that group (i.e., `nums[i+2] - nums[i]`) is less than or equal to `k`.
3. **Result Construction**: If the difference is within the allowed limit, add the group of three elements to the result vector `res`. If at any point the difference exceeds `k`, return an empty vector as it is not possible to divide the array into valid groups.
4. **Return Result**: Finally, return the result vector containing the valid groups of three elements.
Time Complexity: O(n log n) due to the sorting step, where n is the size of the input array `nums`. The grouping step is O(n) as we iterate through the array in steps of three.
*/
