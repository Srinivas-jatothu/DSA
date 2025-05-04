// leetcode problem : https://leetcode.com/problems/number-of-equivalent-domino-pairs/?envType=daily-question&envId=2025-05-04

class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            vector<int> vec(100);
            int result = 0;
            for(auto &d : dominoes) {
                if(d[0] > d[1]) {
                    swap(d[0], d[1]);
                }
                int num = d[0]*10 + d[1]; 
                result += vec[num];
                vec[num]++;
            }
            return result;
        }
    };



    /*
    Algorithm Explanation:
    1. The function `numEquivDominoPairs` takes a vector of vectors `dominoes` as input, where each inner vector represents a domino with two values.
    2. It initializes a vector `vec` of size 100 to keep track of the counts of equivalent domino pairs.
    3. It initializes a variable `result` to 0, which will store the total number of equivalent domino pairs.
    4. It iterates through each domino in the `dominoes` vector.
    5. For each domino, it checks if the first value is greater than the second value. If so, it swaps them to ensure a consistent representation of the domino.
    6. It calculates a unique number `num` for the domino by multiplying the first value by 10 and adding the second value.
    7. It adds the count of equivalent domino pairs for the current domino (stored in `vec[num]`) to the `result` variable.
    8. It increments the count of the current domino in the `vec` vector.
    9. Finally, it returns the total count of equivalent domino pairs stored in `result`.
    10. The time complexity of this algorithm is O(n), where n is the number of dominoes in the input vector.
    */