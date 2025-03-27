//leetcode problem : https://leetcode.com/problems/minimum-index-of-a-valid-split/description/?envType=daily-question&envId=2025-03-27

class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n = nums.size();
    
            unordered_map<int, int> mp1; 
            unordered_map<int, int> mp2; 
    
            for(int &num : nums) {
                mp2[num]++;
            }
    
            for(int i = 0; i < n; i++) {
                int num = nums[i];
    
                mp1[num]++;
                mp2[num]--;
    
                int n1 = i+1;
                int n2 = n-i-1;
    
                if(mp1[num]*2 > n1 && mp2[num]*2 > n2) {
                    return i;
                }
            }
    
            return -1;
        }
    };


    /*
    Algorithm Explanation:
    1. We first create two unordered maps `mp1` and `mp2` to keep track of the frequency of each element in the left and right parts of the array, respectively.
    2. We iterate through the array `nums` and populate `mp2` with the frequency of each element.
    3. For each element in `nums`, we update `mp1` and `mp2` to reflect the current left and right parts of the array.
    4. We calculate the size of the left part `n1` and the size of the right part `n2`.
    5. We check if the frequency of the current element in `mp1` is greater than half of `n1` and the frequency of the current element in `mp2` is greater than half of `n2`.
    6. If both conditions are satisfied, we return the current index `i` as the minimum index of a valid split.
    7. If no valid split is found, we return -1.
    8. The time complexity of this algorithm is O(n), where n is the size of the input array `nums`, as we are iterating through the array only once.
    */