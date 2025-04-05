//leetcode problem : https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/?envType=daily-question&envId=2025-04-05

class Solution {
    public:
        int solve(vector<int>& nums,int id,int Xor){
                if(id>=nums.size()){
                    return Xor;
                }
                int include =solve(nums,id+1,Xor^nums[id]);
                int exclude =solve(nums,id+1,Xor);
                return include+exclude;
            }
    
        int subsetXORSum(vector<int>& nums) {
           
            return solve(nums,0,0);
        }
    };


    /*
    Algorithm explanation:
    1. The function `subsetXORSum` is designed to calculate the sum of XOR values of all possible subsets of a given list of integers `nums`.
    2. It uses a helper function `solve` that takes three parameters:
        - `nums`: the original list of integers.
        - `id`: the current index in the `nums` list.
        - `Xor`: the current XOR value of the subset being constructed.
    3. The `solve` function works recursively:
        - If the current index `id` is greater than or equal to the size of `nums`, it means we have constructed a complete subset, so it returns the current XOR value `Xor`.
        - The function then includes the current element (`nums[id]`) in the XOR calculation and recursively calls itself for the next index (`id + 1`).
        - After that, it calls itself again for the next index without including the current element, effectively exploring both possibilities: including and excluding the current element.
        - Finally, it returns the sum of both cases (including and excluding).
    4. The main function `subsetXORSum` initializes the recursive process by calling `solve` with the starting index `0` and an initial XOR value of `0`.
    5. The final result is the sum of XOR values of all possible subsets of the input list `nums`.
    */