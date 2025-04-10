//leetcode problem: https://leetcode.com/problems/count-the-number-of-powerful-integers/?envType=daily-question&envId=2025-04-10

class Solution {
    public:
        long long solve(string& str, string& inputSuffix, int limit) {
            if(str.length() < inputSuffix.length()) {
                return 0;
            }
            long long count = 0;
            string trailString = str.substr(str.length() - inputSuffix.length()); 
            int remainL = str.length() - inputSuffix.length();
    
            for(int i = 0; i < remainL; i++) {
                int digit = str[i] - '0';
    
                if(digit <= limit) {
                    count += digit * pow(limit+1, remainL-i-1);
                } else {
                    count += pow(limit+1, remainL-i); 
                    return count;
                }
            }
    
            if(trailString >= inputSuffix) {
                count += 1;
            }
            return count;
    
        }
        long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
            string startStr = to_string(start-1);
            string finishStr = to_string(finish);
    
             return solve(finishStr, s, limit) - solve(startStr, s, limit);
        }
    };

    


    /*
    Algorithm Explanation:
    1. The function `numberOfPowerfulInt` is designed to count the number of powerful integers in a given range `[start, finish]` that satisfy a specific condition based on the input string `s` and the integer `limit`.
    2. The function `solve` is a helper function that calculates the count of powerful integers in a given range.
    3. The function takes the following parameters:
        - `str`: The string representation of the number.
        - `inputSuffix`: The suffix string that needs to be compared.
        - `limit`: The limit for the powerful integers.
    4. The function first checks if the length of `str` is less than the length of `inputSuffix`. If it is, it returns 0 as there are no powerful integers in that case.
    5. It initializes a variable `count` to keep track of the number of powerful integers found.
    6. It extracts the trailing substring `trailString` from `str` that has the same length as `inputSuffix`.
    7. It calculates the remaining length `remainL` of the string after removing the suffix.
    8. It iterates through the characters of `str` up to the remaining length and checks if the digit is less than or equal to the limit.
    9. If it is, it calculates the contribution of that digit to the count based on its position and adds it to `count`.
    10. If the digit is greater than the limit, it adds the count of powerful integers for that position and returns the count.
    11. After iterating through the characters, it checks if the `trailString` is greater than or equal to `inputSuffix`. If it is, it increments the count by 1.
    12. Finally, the function returns the count of powerful integers in the range `[start, finish]` by calling `solve` for both `finish` and `start-1` and subtracting the results.
    13. The time complexity of this algorithm is O(n), where n is the length of the input string, as we are iterating through the string only once.
    */