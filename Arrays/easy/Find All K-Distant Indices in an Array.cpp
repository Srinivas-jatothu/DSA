// leetcode problem : https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/description/?envType=daily-question&envId=2025-06-24


class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n= nums.size();
        vector<int>res;
        for(int i=0;i<n;i++){
            if(nums[i]==key){
                int start=max(i-k,0);
                int end=min(i+k,n-1);

                if(res.size()>0 && res.back()>=start){
                    start=res.back()+1;
                }
                for(int j=start;j<=end;j++){
                    res.push_back(j);
                }
            }
        }
            return res;
    }
};


/*
Algorithm Explanation:
1. Initialize an empty vector `res` to store the indices.
2. Iterate through each index `i` of the `nums` array.
3. If the current element `nums[i]` is equal to `key`, calculate the
   start and end indices for the k-distant range:
   - `start` is the maximum of `i-k` and `0` (to ensure it doesn't go below 0).
   - `end` is the minimum of `i+k` and `n-1` (to ensure it doesn't exceed the last index).
4. If `res` is not empty and the last index in `res` is greater than or equal to `start`,
   update `start` to be one more than the last index in `res` to avoid 
    overlapping indices.
5. Iterate from `start` to `end`, adding each index to `res`.
6. Finally, return the `res` vector containing all k-distant indices.
7. The time complexity is O(n^2) in the worst case, where n is the size of the `nums` array.
8. The space complexity is O(n) for storing the result.
*/