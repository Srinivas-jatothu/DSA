// leetcode problem : https://leetcode.com/problems/count-largest-group/description/?envType=daily-question&envId=2025-04-23


class Solution {
    public:
        int finddigitsum(int num){
            int sum=0;
            while(num){
                sum+=num%10;
                num/=10;
            }
            return sum;
        }
        int countLargestGroup(int n) {
            unordered_map<int,int>mp;
            int maxsize=0;
            int count=0;
            for(int i=1;i<=n;i++){
                int digitsum=finddigitsum(i);
                mp[digitsum]++;
                if(mp[digitsum]==maxsize){
                    count++;
                }
                else if(mp[digitsum]>maxsize){
                    maxsize=mp[digitsum];
                    count=1;
                }
            }
            return count;
        }
    };




    /*
    Algorithm Explanation:
    1. Create a function `finddigitsum` that calculates the sum of digits of a number.
    2. Create a function `countLargestGroup` that takes an integer `n` as input.
    3. Initialize an unordered map `mp` to store the frequency of digit sums.
    4. Initialize `maxsize` to keep track of the maximum frequency and `count` to count the number of groups with that frequency.
    5. Loop through numbers from 1 to `n`:
        - Calculate the digit sum using `finddigitsum`.
        - Update the frequency in the map.
        - If the frequency equals `maxsize`, increment `count`.
        - If the frequency exceeds `maxsize`, update `maxsize` and reset `count` to 1.
    6. Return `count` as the result.

    */