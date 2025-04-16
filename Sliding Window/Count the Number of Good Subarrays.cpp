// leetcode problem : https://leetcode.com/problems/count-the-number-of-good-subarrays/description/?envType=daily-question&envId=2025-04-16

class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            int i=0;
            int j=0;
            long long res=0;
            unordered_map<int,int>mp;
            long long pair=0;
            int n=nums.size();
            while(j<n){
                pair+=mp[nums[j]];
                mp[nums[j]]++;
                while(pair>=k){
                    res+=(n-j);
                    mp[nums[i]]--;
                    pair-=mp[nums[i]];
                    i++;
                }
                j++;
            }
            return res;
        }
    };



    /*
    Algorithm explanation:
    1. Initialize two pointers i and j to 0, and a result variable res to 0.
    2. Create a hash map mp to store the frequency of elements in the current window.
    3. Initialize a variable pair to count the number of pairs in the current window.
    4. Iterate through the array using the j pointer.
    5. For each element nums[j], add its frequency to pair and increment its count in mp.
    6. While pair is greater than or equal to k, it means we have found a valid subarray.
    7. In this case, add the number of remaining elements (n - j) to res, as all these elements can form valid subarrays with the current window.
    8. Decrease the frequency of nums[i] in mp and update pair accordingly.
    9. Increment i to shrink the window from the left.
    10. Continue until j reaches the end of the array.
    11. Return the final result res.
    */