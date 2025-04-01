//leetcode problem : https://leetcode.com/problems/solving-questions-with-brainpower/description/?envType=daily-question&envId=2025-04-01


class Solution {
    public:
        int n;
        
        long long solve(int i, vector<vector<int>>& questions, vector<long long> &t) {        
            if(i >= n)
                return 0;
            
            if(t[i] != -1)
                return t[i];
            
            long long taken     = questions[i][0] + solve(i+questions[i][1]+1, questions, t);        
            long long not_taken = solve(i+1, questions, t);        
            return t[i] = max(taken, not_taken);
            
        }    
        long long mostPoints(vector<vector<int>>& questions) {
            n = questions.size();
            vector<long long> t(n+1, -1);
            return solve(0, questions, t);
        }
    };




    /*
    Algorithm explanation:
    1. Define a recursive function `solve` that takes the current index `i`, the `questions` vector, and a memoization vector `t` as parameters.
    2. If `i` is greater than or equal to `n`, return 0 (base case).
    3. If the value at index `i` in `t` is not -1, return the memoized value (to avoid redundant calculations).
    4. Calculate the maximum points if the current question is taken (`taken`) by adding the points of the current question and recursively calling `solve` with the next question index after skipping the brainpower.
    5. Calculate the maximum points if the current question is not taken (`not_taken`) by recursively calling `solve` with the next question index.
    6. Store the maximum of `taken` and `not_taken` in the memoization vector `t[i]`.
    7. Return the value of `t[i]`.
    8. In the `mostPoints` function, initialize the memoization vector `t` with -1 and call the `solve` function starting from index 0.
    9. Return the result of the `solve` function, which gives the maximum points that can be obtained by solving the questions.
    10. The result is the maximum points that can be obtained by solving the questions while considering the brainpower required for each question.
    */