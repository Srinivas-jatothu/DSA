// leetcode problem : https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/description/?envType=daily-question&envId=2025-06-15

class Solution {
public:
    int maxDiff(int num) {
        string str1 = to_string(num);
        string str2 = str1;

        int idx = str1.find_first_not_of('9');
        if(idx != string::npos) {
            char ch = str1[idx];
            replace(begin(str1), end(str1), ch, '9');
        }

        for(int i = 0; i < str2.length(); i++) {
            char ch = str2[i];
            if(i == 0) {
                if(ch != '1') {
                    replace(begin(str2), end(str2), ch, '1');
                    break;
                }
            } else if(ch != '0' && ch != str2[0]) {
                replace(begin(str2), end(str2), ch, '0');
                break;
            }
        }
        return stoi(str1) - stoi(str2);
    }
};



/*
Algorithm Explanation:
1. Convert the input number `num` to a string representation `str1` and create a copy `str2`.
2. Find the first character in `str1` that is not '9'. If found, replace all occurrences of that character with '9' to maximize the number.
3. For `str2`, iterate through the characters:
   - If the first character is not '1', replace it with '1' to minimize the number.
   - For subsequent characters, if they are not '0' and not equal to the first character, replace them with '0' to minimize the number.
4. Finally, convert both modified strings back to integers and return the difference between the maximum and minimum values.
5. Time Complexity: O(n), where n is the number of digits in the input number.
*/