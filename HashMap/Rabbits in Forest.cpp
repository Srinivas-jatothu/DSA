// leetcode problem : https://leetcode.com/problems/rabbits-in-forest/description/?envType=daily-question&envId=2025-04-20

class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            int n = answers.size();
            unordered_map<int, int> mp;
            for (int i = 0; i < n; i++) {
                mp[answers[i]]++;
            }
            int total;
            for (auto& j : mp) {
                int x= j.first;
                int y=j.second;
                int grpsize=(x+1);
                int grp=ceil((double)y/grpsize);
                total+=grp*grpsize;
            }
            return total;
        }
    };

    

    /*
    Algorithm explanation:
    1. The function numRabbits takes a vector of integers answers as input, which represents the number of rabbits in a forest.
    2. It initializes a variable n to the size of the answers vector and creates an unordered_map mp to store the frequency of each answer.
    3. A loop iterates through each element in the answers vector and increments the count of each answer in the mp map.
    4. A variable total is initialized to 0 to keep track of the total number of rabbits.
    5. Another loop iterates through each key-value pair in the mp map.
    6. For each key-value pair, it calculates the group size as (x + 1), where x is the answer (the number of rabbits with the same color).
    7. It calculates the number of groups needed to accommodate the rabbits with the same answer using ceil((double)y / grpsize), where y is the frequency of the answer.
    8. The total number of rabbits is updated by multiplying the number of groups by the group size.
    9. Finally, the function returns the total variable, which represents the total number of rabbits in the forest.
    10. The function uses the unordered_map to efficiently count the frequency of each answer and calculate the total number of rabbits based on the given conditions.
    11. The use of ceil ensures that if there are any remaining rabbits that do not fit into a complete group, they are counted as an additional group.
    12. The final result is the total number of rabbits in the forest, taking into account the answers provided by the rabbits.
    13. The time complexity of this algorithm is O(n), where n is the size of the answers vector, as it iterates through the vector and the map once.
    */