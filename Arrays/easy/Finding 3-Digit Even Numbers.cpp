// leetcode problem : https://leetcode.com/problems/finding-3-digit-even-numbers/description/?envType=daily-question&envId=2025-05-12

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> st;
        int n = digits.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(i == j || j == k || i == k) {
                        continue;
                    }

                    int num = digits[i]*100 + digits[j] * 10 + digits[k];

                    if(num >= 100 && num%2 == 0) {
                        st.insert(num);
                    }
                }
            }
        }

        vector<int> result(begin(st), end(st));
        sort(begin(result), end(result));
        return result;
    }
};



/*
Algorithm Explanation:
1. Initialize an unordered set `st` to store unique even 3-digit numbers.
2. Get the size of the input array `digits` and store it in `n`.
3. Use three nested loops to iterate through all combinations of three digits.
4. In each iteration, check if the indices are distinct (i.e., not equal).
5. If they are distinct, construct a 3-digit number using the digits at those indices.
6. Check if the number is a 3-digit number and even (i.e., divisible by 2).
7. If both conditions are satisfied, insert the number into the set `st`.
8. After all iterations, convert the set `st` to a vector `result`.
9. Sort the vector `result` in ascending order.
10. Return the sorted vector `result`.
11. The time complexity of this solution is O(n^3) due to the three nested loops.
*/