//leetcode problem : https://leetcode.com/problems/apply-operations-to-maximize-score/description/?envType=daily-question&envId=2025-03-29


class Solution {
    public:
     int maximumScore(vector<int>& nums, int k) {
       const int n = nums.size();
       const int mx = ranges::max(nums);
       const vector<int> minPrimeFactors = sieveEratosthenes(mx + 1);
       const vector<int> primeScores = getPrimeScores(nums, minPrimeFactors);
       int ans = 1;
       vector<int> left(n, -1);
       vector<int> right(n, n);
       stack<int> stack;
       for (int i = n - 1; i >= 0; --i) {
         while (!stack.empty() && primeScores[stack.top()] <= primeScores[i])
           left[stack.top()] = i, stack.pop();
         stack.push(i);
       }
   
       stack = std::stack<int>();
   
       for (int i = 0; i < n; ++i) {
         while (!stack.empty() && primeScores[stack.top()] < primeScores[i])
           right[stack.top()] = i, stack.pop();
         stack.push(i);
       }
   
       vector<pair<int, int>> numAndIndexes;
   
       for (int i = 0; i < n; ++i)
         numAndIndexes.emplace_back(nums[i], i);
   
       ranges::sort(numAndIndexes,
                    [&](const pair<int, int>& a, const pair<int, int>& b) {
         return a.first == b.first ? a.second < b.second : a.first > b.first;
       });
   
       for (const auto& [num, i] : numAndIndexes) {
         const long rangeCount = static_cast<long>(i - left[i]) * (right[i] - i);
         const long actualCount = min(rangeCount, static_cast<long>(k));
         k -= actualCount;
         ans = static_cast<long>(ans) * modPow(num, actualCount) % kMod;
       }
   
       return ans;
     }
   
    private:
     static constexpr int kMod = 1'000'000'007;
   
     long modPow(long x, long n) {
       if (n == 0)
         return 1;
       if (n % 2 == 1)
         return x * modPow(x % kMod, (n - 1)) % kMod;
       return modPow(x * x % kMod, (n / 2)) % kMod;
     }
   
     vector<int> sieveEratosthenes(int n) {
       vector<int> minPrimeFactors(n + 1);
       iota(minPrimeFactors.begin() + 2, minPrimeFactors.end(), 2);
       for (int i = 2; i * i < n; ++i)
         if (minPrimeFactors[i] == i)  
           for (int j = i * i; j < n; j += i)
             minPrimeFactors[j] = min(minPrimeFactors[j], i);
       return minPrimeFactors;
     }
   
     vector<int> getPrimeScores(const vector<int>& nums,
                                const vector<int>& minPrimeFactors) {
       vector<int> primeScores;
       for (const int num : nums)
         primeScores.push_back(getPrimeScore(num, minPrimeFactors));
       return primeScores;
     }
   
     int getPrimeScore(int num, const vector<int>& minPrimeFactors) {
       unordered_set<int> primeFactors;
       while (num > 1) {
         const int divisor = minPrimeFactors[num];
         primeFactors.insert(divisor);
         while (num % divisor == 0)
           num /= divisor;
       }
       return primeFactors.size();
     }
   };

/*
Algorithm Explanation:
1. We first create a vector `minPrimeFactors` to store the smallest prime factor for each number up to the maximum number in `nums`.
2. We then create a vector `primeScores` to store the number of distinct prime factors for each number in `nums` using the smallest prime factors.
3. We initialize two vectors `left` and `right` to keep track of the range of indices for each number in `nums` based on their prime scores.
4. We use a stack to find the left and right boundaries for each number in `nums` based on their prime scores.
5. We create a vector `numAndIndexes` to store the numbers along with their indices.
6. We sort this vector in descending order based on the numbers and ascending order based on the indices.
7. We iterate through the sorted vector and calculate the range count for each number based on its left and right boundaries.
8. We take the minimum of the range count and `k` to determine how many times we can use this number to maximize the score.
9. We update `k` and calculate the score using modular exponentiation.
10. Finally, we return the score modulo `1,000,000,007`.
11. The time complexity of this algorithm is O(n log n) due to the sorting step, and the space complexity is O(n) for storing the prime factors and scores.
12. The algorithm efficiently handles the constraints and provides the correct result for the problem.
13. The use of modular arithmetic ensures that we do not encounter overflow issues while calculating the score.
14. The algorithm is optimized for large inputs and performs well within the given constraints.
15. The use of unordered_set to store prime factors ensures that we only count distinct prime factors for each number.
16. The algorithm is designed to be efficient and concise, making it easy to understand and maintain.
17. The use of helper functions for modular exponentiation and prime factorization keeps the code organized and modular.
*/

