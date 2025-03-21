// Leetcode Problem : https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/?envType=daily-question&envId=2025-03-19


class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int n=nums.size();
            vector<bool>flipped(n,false);    
            int Current_flipped=0;
            int res=0;
    
            for(int i=0;i<n;i++){
                if(i>=3 && flipped[i-3]==true){    ///if the last 3 elements are flipped, we need to flip the current element back to its original state
                    Current_flipped--;
                }
                if(Current_flipped%2 == nums[i]){   //if the current element is not equal to 1, we need to flip it
                    if(i+3>n){
                        return -1;
                    }
                    Current_flipped++;
                    flipped[i]=true;
                    res++;
                }
            }
            return res;
        }   
    };


/* 
Algorith Explanation:
1. We initialize an array `flipped` to track which elements have been flipped.
2. `Current_flipped` keeps a count of how many flips affect the current element.
3. We iterate through the array. If the current element is not `1`, we check if flipping it (and the next two elements) is possible.
4. If flipping is possible, we update the flip count and `flipped` array to reflect the operation.
5. If we can't flip due to the array size constraints, we return `-1`.
6. Finally, we return the total number of flip operations required.
*/