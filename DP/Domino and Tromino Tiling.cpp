// leetcode problem : https://leetcode.com/problems/domino-and-tromino-tiling/description/?envType=daily-question&envId=2025-05-05


class Solution {
    public:
        int M = 1000000007;
        int t[1001];
        int solve(int n) {
             if(n == 1 || n == 2)
                return n;
            if(n == 3)
                return 5;        
            if(t[n] != -1)
                return t[n];        
            return t[n] = (2*solve(n-1)%M + solve(n-3)%M)%M;
        }
        
        int numTilings(int n) {       
            memset(t, -1, sizeof(t));    
            return solve(n);
            
        }
    };


    /*
    Algorithm Explanation:
    1. The function `numTilings` takes an integer `n` as input, which represents the length of the board.
    2. It initializes a static array `t` of size 1001 to store the results of subproblems, and sets all elements to -1.
    3. It calls the helper function `solve` with the input `n` to calculate the number of ways to tile the board.
    4. The `solve` function uses memoization to store the results of previously computed subproblems in the array `t`.
    5. The base cases are defined for `n = 1`, `n = 2`, and `n = 3`:
        - For `n = 1`, there is only one way to tile the board (using a single domino).
        - For `n = 2`, there are two ways to tile the board (using two horizontal dominoes or two vertical dominoes).
        - For `n = 3`, there are five ways to tile the board (using three horizontal dominoes, one horizontal and two vertical dominoes, etc.).
    6. For larger values of `n`, the function uses the recurrence relation:
        - `t[n] = (2 * t[n-1] + t[n-3]) % M`, where `M` is a large prime number (1000000007) to avoid overflow.
    7. The recurrence relation is derived from the fact that there are two ways to place a domino on the board (horizontally or vertically), and the number of ways to fill the remaining space depends on the previous states.
    8. The function returns the result of `solve(n)`, which is the number of ways to tile the board of length `n`.
    9. The time complexity of this algorithm is O(n), where n is the length of the board, due to the memoization technique used to avoid redundant calculations.
    
    */