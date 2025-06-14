// leetcode problem: https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/description/?envType=daily-question&envId=2025-06-14

class Solution {
public:
    int minMaxDifference(int num) {
        string str1 = to_string(num);
        string str2 = str1;

        int idx = str1.find_first_not_of('9');
        if(idx != string::npos) {
            char ch = str1[idx];
            replace(begin(str1), end(str1), ch, '9');
        }

        char ch = str2[0]; 
        replace(begin(str2), end(str2), ch, '0');

        return stoi(str1) - stoi(str2);
    }
};


/*
Algorithm Explanation:
1. Convert the input number `num` to a string representation `str1` and create a copy `str2`.
2. Find the first character in `str1` that is not '9'. If found, replace all occurrences of that character with '9' to maximize the number.
3. For `str2`, replace the first character with '0' to minimize the number.
4. Finally, convert both modified strings back to integers and return the difference between the maximum and minimum values.
*/