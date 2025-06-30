// leetcode problem : https://leetcode.com/problems/longest-harmonious-subsequence/description/?envType=daily-question&envId=2025-06-30

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int i=0; i<n; i++)
        {
            freq[nums[i]] = freq[nums[i]]+1;
        }
        int res=0;

        for(int i=0;i<nums.size();i++){
            int mini=nums[i];
            int maxi=mini+1;
            if(freq[maxi]){
                res=max(res,freq[mini]+freq[maxi]);
            }
        
        }
        return res;
    }
};


/*
Algorithm Explanation:
1. The function `findLHS` takes a vector of integers `nums` as input.
2. It initializes an integer `n` to the size of the `nums` vector.
3. It creates an unordered map `freq` to store the frequency of each element in `nums`.
4. It iterates through the `nums` vector and populates the `freq` map with the count of each element.
5. It initializes an integer `res` to 0, which will store the length of the longest harmonious subsequence found.
6. It then iterates through each element in `nums`:
7. For each element, it sets `mini` to the current element and `maxi` to `mini + 1`.
8. It checks if `maxi` exists in the `freq` map.
9. If `maxi` exists, it calculates the sum of the frequencies of `mini` and `maxi`, and updates `res` to be the maximum of its current value and this sum.
10. Finally, it returns `res`, which is the length of the longest harmonious subsequence.
Time Complexity: O(n) for iterating through the `nums` vector and populating the `freq` map, and O(n) for the second loop, resulting in an overall time complexity of O(n).
Space Complexity: O(n) for the `freq` map to store the frequencies of the elements in `nums`.
*/