// leetcode problem : https://leetcode.com/problems/count-the-hidden-sequences/description/?envType=daily-question&envId=2025-04-21

class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            int curr=0;
            int minv=0;
            int maxv=0;
            for(int &i : differences){
                curr+=i;
                minv=min(minv,curr);
                maxv=max(maxv,curr);
                if((upper-maxv)-(lower-minv)+1 <=0){
                    return 0;
                }
            }
            return (upper-maxv)-(lower-minv)+1;
        }
    };


    /*
    Algorithm explanation:
    1. The function numberOfArrays takes a vector of integers differences, and two integers lower and upper as input.
    2. It initializes a variable curr to 0, which will be used to keep track of the current value as we iterate through the differences.
    3. It also initializes two variables minv and maxv to 0, which will be used to keep track of the minimum and maximum values encountered during the iteration.
    4. A loop iterates through each element in the differences vector.
    5. For each element, it adds the current difference to curr, updating the current value.
    6. It then updates minv to be the minimum of minv and curr, and maxv to be the maximum of maxv and curr.
    7. After processing all differences, it checks if the range between upper - maxv and lower - minv is less than or equal to 0.
    8. If it is, it means there are no valid arrays that can be formed, so the function returns 0.
    9. If the range is valid, it calculates the number of valid arrays by subtracting (lower - minv) from (upper - maxv) and adding 1.
    10. Finally, it returns the calculated number of valid arrays.
    11. The algorithm efficiently keeps track of the current value and the minimum and maximum values encountered during the iteration.
    12. The time complexity of this algorithm is O(n), where n is the size of the differences vector, as it iterates through the vector once.
    */