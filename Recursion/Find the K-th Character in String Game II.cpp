// leetcode problem : https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/description/?envType=daily-question&envId=2025-07-04


class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if( k==1){
            return 'a';
        }
        long long n=operations.size();
        long long newk=-1;
        long long newoperation=-1;
        long long length=1;
        for(int i=0;i<n;i++){
            length*=2;
            if(length>=k){
                  newoperation=operations[i];
                newk=k-(length/2);
                break;
            }
        }
        char ch=kthCharacter(newk,operations);
        if(newoperation == 0){
            return ch;
        }
        else if(ch =='z'){
            return 'a';
        }
            return  ch+1;
        

    }
};

/*
Algorithm Explanation:
1. If `k` is 1, return 'a' since the first character is always 'a'.
2. Initialize `n` to the size of `operations`, and `length` to 1, which represents the length of the string at each step.
3. Iterate through the `operations` vector to find the first operation that results in a string length that is greater than or equal to `k`.
4. Calculate the new value of `k` as `k - (length / 2)` to find the position in the previous string.
5. Recursively call `kthCharacter` with the new `k` and the same `operations` vector to find the character at that position.
6. If the operation is 0, return the character as it is.
7. If the character is 'z', return 'a' since the next character after 'z' wraps around to 'a'.
8. Otherwise, return the next character by incrementing the character by 1.
// Time Complexity: O(n), where n is the number of operations.
// Space Complexity: O(1), since we are using a constant amount of space for variables
*/