// leetcode problem : https://leetcode.com/problems/count-good-triplets/description/?envType=daily-question&envId=2025-04-14


class Solution {
    public:
        int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
            int n = arr.size();
            int count = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    for (int k = j + 1; k < n; k++) {
                        if (abs(arr[i] - arr[j]) <= a &&
                            abs(arr[j] - arr[k]) <= b &&
                            abs(arr[i] - arr[k]) <= c) {
                            count++;
                        }
                    }
                }
            }
            return count;
        }
    };

    
    /*
    Algorithm Explanation:
    1. The function `countGoodTriplets` takes a vector of integers `arr` and three integers `a`, `b`, and `c` as input.
    2. It initializes a variable `n` to store the size of the input array and a variable `count` to keep track of the number of good triplets found.
    3. It uses three nested loops to iterate through all possible triplets `(i, j, k)` in the array, where `i < j < k`.
    4. For each triplet, it checks if the absolute differences between the elements satisfy the conditions:
        - `abs(arr[i] - arr[j]) <= a`
        - `abs(arr[j] - arr[k]) <= b`
        - `abs(arr[i] - arr[k]) <= c`
    5. If all conditions are satisfied, it increments the `count` variable by 1.
    6. Finally, it returns the total count of good triplets found in the array.
    7. The time complexity of this algorithm is O(n^3), where n is the size of the input array, as we are using three nested loops to iterate through all possible triplets.
    */
   