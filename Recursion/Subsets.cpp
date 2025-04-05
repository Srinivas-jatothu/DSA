//leetcode problem : https://leetcode.com/problems/subsets/description/

class Solution {
    public:
    vector<vector<int>>res;
        vector<vector<int>>solve(vector<int>& nums,vector<int>temp,int id){
            if(id>=nums.size()){
                res.push_back(temp);
                return res;
            }
            temp.push_back(nums[id]);
            solve(nums,temp,id+1);
            temp.pop_back();
            solve(nums,temp,id+1);
            return res;
        }
    
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<int>temp;
            return solve(nums,temp,0);
    
        }
    };


    /*
    Algorithm explanation:
    1. The function `subsets` is designed to generate all possible subsets of a given list of integers `nums`.
    2. It uses a helper function `solve` that takes three parameters:
        - `nums`: the original list of integers.
        - `temp`: a temporary list to store the current subset being constructed.
        - `id`: the current index in the `nums` list.
    3. The `solve` function works recursively:
        - If the current index `id` is greater than or equal to the size of `nums`, it means we have constructed a complete subset, so we add it to the result list `res`.
        - The function then includes the current element (`nums[id]`) in the temporary list `temp` and recursively calls itself for the next index (`id + 1`).
        - After that, it removes the last added element from `temp` (backtracking) and calls itself again for the next index without including the current element.
        - This way, it explores both possibilities: including and excluding the current element.
    */