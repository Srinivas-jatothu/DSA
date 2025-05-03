// leetcode problem : https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/description/?envType=daily-question&envId=2025-05-03


class Solution {
    public:
    
        int find(vector<int>& tops, vector<int>& bottoms, int val) {
            int n = tops.size();
    
            int swapTop = 0;
            int swapBottom = 0;
    
            for(int i = 0; i < n; i++) {
                if(tops[i] != val && bottoms[i] != val) {
                    return -1;
                } else if(tops[i] != val) {
                    swapTop++;
                } else if(bottoms[i] != val) {
                    swapBottom++;
                }
            }
    
            return min(swapTop, swapBottom);
        }
    
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            int result = INT_MAX;
    
            for(int val = 1; val <= 6; val++) {
                int swaps = find(tops, bottoms, val);
    
                if(swaps != -1) {
                    result = min(result, swaps);
                }
            }
    
            return result == INT_MAX ? -1 : result;
        }
    };




/*
Algorithm Explanation:
1. The function `find` takes two vectors `tops` and `bottoms`, and an integer `val` as input.
2. It initializes two variables `swapTop` and `swapBottom` to count the number of swaps needed for the top and bottom rows, respectively.
3. It iterates through the elements of the `tops` and `bottoms` vectors.
4. If both the top and bottom values at index `i` are not equal to `val`, it returns -1, indicating that it's impossible to make all values equal to `val`.
5. If the top value is not equal to `val`, it increments `swapTop`. If the bottom value is not equal to `val`, it increments `swapBottom`.
6. After iterating through all elements, it returns the minimum of `swapTop` and `swapBottom`, which represents the minimum number of swaps needed to make all values equal to `val`.
7. The function `minDominoRotations` iterates through all possible values (1 to 6) and calls the `find` function for each value.
8. It keeps track of the minimum number of swaps needed for any value.
9. If no valid swaps were found, it returns -1. Otherwise, it returns the minimum number of swaps found.
10. The time complexity of this algorithm is O(n), where n is the length of the input vectors `tops` and `bottoms`.
*/