// leetcode problem : https://leetcode.com/problems/count-and-say/description/?envType=daily-question&envId=2025-04-18


class Solution {
    public:
        string countAndSay(int n) {
            if(n==1){
                return "1";
            }       
            string say=countAndSay(n-1);
            string result="";
            for(int i = 0; i<say.length();i++) {
                int count = 1;
                char ch = say[i];
                while(i < say.length()-1 && say[i] == say[i+1]) {
                    count++;
                    i++;
                }            
                result += to_string(count) + string(1, say[i]);            
            }
            return result;
        }
    };



    /*
    Algorithm explanation:
    1. The function countAndSay takes an integer n as input and returns the nth term of the "count and say" sequence.
    2. The base case is when n is 1, in which case the function returns "1".
    3. For n greater than 1, the function recursively calls itself with n-1 to get the previous term in the sequence.
    4. The result of the recursive call is stored in the variable say.
    5. An empty string result is initialized to build the current term.
    6. A loop iterates through each character in the say string.
    7. For each character, a count variable is initialized to 1 to count consecutive occurrences of the same character.
    8. A nested while loop checks if the next character is the same as the current character and increments the count variable accordingly.
    9. After counting consecutive characters, the count and the character are concatenated to the result string.
    10. The loop continues until all characters in the say string have been processed.
    11. Finally, the function returns the result string, which represents the nth term of the "count and say" sequence.
    */