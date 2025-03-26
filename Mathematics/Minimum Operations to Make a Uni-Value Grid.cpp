//leetcode problem : https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/?envType=daily-question&envId=2025-03-26

class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            int m = grid.size();
            int n = grid[0].size();
            vector<int> vec;
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    vec.push_back(grid[i][j]);
                }
            }
            int L = vec.size(); 
            nth_element(begin(vec), begin(vec) + L/2, end(vec)); 
    
            int target = vec[L/2];
            int result = 0;
            for(int &num : vec) { 
                if(num%x != target%x) {
                    return -1;
                }
                result += abs(target-num)/x;
            }
            return result;
        }
    };



    /*
    Algorithm Explanation:
    1. We first flatten the grid into a 1D vector `vec`.
    2. We find the median of the elements in `vec` using the nth_element function.
    3. We set the target value to be the median of the elements in `vec`.
    4. We iterate through the elements in `vec` and check if the difference between the element and the target value is divisible by `x`.
    5. If the difference is not divisible by `x`, we return -1 as it is not possible to make all elements equal.
    6. Otherwise, we add the absolute difference between the element and the target value divided by `x` to the result.
    7. Finally, we return the result.
    */