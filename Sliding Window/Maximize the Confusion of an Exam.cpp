// leetcode problem : https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i=0,j=0;
        int n=answerKey.length();
        int count_false=0;
        int res=0;
        //case 1 : Changing 'F' to 'T'
        while(j<n){
            if(answerKey[j]=='F'){
                count_false++;
            }
            while(count_false>k){
                if(answerKey[i]=='F'){
                    count_false--;
                }
                i++;
            }
            res=max(res,j-i+1);
            j++;
        }

         
        //case 1 : Changing 'T' to 'F'
        i=0,j=0;
        int count_true=0;
        while(j<n){
            if(answerKey[j]=='T'){
                count_true++;
            }
            while(count_true>k){
                if(answerKey[i]=='T'){
                    count_true--;
                }
                i++;
            }
            res=max(res,j-i+1);
            j++;
        }

        return res;
    }
};



/*
Algorithm Explanation:
1. Initialize two pointers `i` and `j` to 0, and `n` as the length of the `answerKey`.
2. Create a variable `count_false` to count the number of 'F's in the current window and `res` to store the maximum length of valid substring found.
3. Use a while loop to iterate through the string with the `j` pointer:
   - If the character at index `j` is 'F', increment `count_false`.
   - While `count_false` exceeds `k`, increment `i` to shrink the window from the left and decrement `count_false` if the character at index `i` is 'F'.
   - Update `res` with the maximum of its current value and the length of the current window (`j - i + 1`).
   - Increment `j` to expand the window to the right.
4. After processing the first case, reset `i`, `j`, and `count_true` to handle the second case where we change 'T' to 'F':
   - Repeat the same steps as above, but now count 'T's instead of 'F's.
5. Finally, return `res`, which contains the maximum length of the substring that can be formed by changing at most `k` characters.
Time Complexity: O(n), where n is the length of the `answerKey`. Each character is processed at most twice (once by `j` and once by `i`), ensuring linear time complexity.
*/