// Leetcode Problem : https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/?envType=daily-question&envId=2025-03-19


class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int n=nums.size();
            vector<bool>flipped(n,false);
            int Current_flipped=0;
            int res=0;
    
            for(int i=0;i<n;i++){
                if(i>=3 && flipped[i-3]==true){
                    Current_flipped--;
                }
                if(Current_flipped%2 == nums[i]){
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