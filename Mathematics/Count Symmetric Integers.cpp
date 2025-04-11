// leetcode problem : https://leetcode.com/problems/count-symmetric-integers/description/?envType=daily-question&envId=2025-04-11

class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int count = 0;
    
            for(int num = low; num <= high; num++) {
                if(num >= 10 && num <= 99 && num % 11 == 0) { 
                    count++;
                } else if(num >= 1000 && num <= 9999) { 
                    int first  = num/1000;
                    int second = (num/100) % 10;
                    int third  = (num / 10) % 10;
                    int fourth = (num % 10);
                    if(first+second == third + fourth) {
                        count++;
                    }
                }
            }
            return count;
        }
    };

    /*
    Algorithm Explanation:
    1. The function `countSymmetricIntegers` takes two integers `low` and `high` as input, representing the range of numbers to check for symmetry.
    2. It initializes a variable `count` to keep track of the number of symmetric integers found in the range.      
    3. It iterates through each number `num` in the range from `low` to `high`.
    4. For each number, it checks if it is a two-digit number (between 10 and 99) and if it is symmetric (i.e., the first digit is equal to the second digit). If so, it increments the count.
    5. If the number is a four-digit number (between 1000 and 9999), it extracts the individual digits using integer division and modulo operations.
    6. It checks if the sum of the first two digits is equal to the sum of the last two digits. If they are equal, it increments the count.
    7. Finally, it returns the total count of symmetric integers found in the specified range.
    8. The time complexity of this algorithm is O(n), where n is the number of integers in the range [low, high], as it iterates through each number once.
    */


