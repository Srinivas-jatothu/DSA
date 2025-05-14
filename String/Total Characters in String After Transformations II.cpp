// leetcode problem :  https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/description/?envType=daily-question&envId=2025-05-14


class Solution {
 public:
  int lengthAfterTransformations(string s, int t, vector<int>& nums) {
    const vector<vector<int>> T = getTransformationMatrix(nums);
    const vector poweredT = matrixPow(T, t);
    vector<int> count(26);
    vector<long> lengths(26);

    for (const char c : s)
      ++count[c - 'a'];

    for (int i = 0; i < 26; ++i)
      for (int j = 0; j < 26; ++j) {
        lengths[j] += static_cast<long>(count[i]) * poweredT[i][j];
        lengths[j] %= kMod;
      }

    return accumulate(lengths.begin(), lengths.end(), 0L) % kMod;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  vector<vector<int>> getTransformationMatrix(const vector<int>& nums) {
    vector<vector<int>> T(26, vector<int>(26));
    for (int i = 0; i < nums.size(); ++i)
      for (int step = 1; step <= nums[i]; ++step)
        ++T[i][(i + step) % 26];
    return T;
  }

  vector<vector<int>> getIdentityMatrix(int sz) {
    vector<vector<int>> I(sz, vector<int>(sz));
    for (int i = 0; i < sz; ++i)
      I[i][i] = 1;
    return I;
  }

  vector<vector<int>> matrixMult(const vector<vector<int>>& A,
                                 const vector<vector<int>>& B) {
    const int sz = A.size();
    vector<vector<int>> C(sz, vector<int>(sz));
    for (int i = 0; i < sz; ++i)
      for (int j = 0; j < sz; ++j)
        for (int k = 0; k < sz; ++k)
          C[i][j] = (C[i][j] + static_cast<long>(A[i][k]) * B[k][j]) % kMod;
    return C;
  }

  vector<vector<int>> matrixPow(const vector<vector<int>>& M, int n) {
    if (n == 0)
      return getIdentityMatrix(M.size());
    if (n % 2 == 1)
      return matrixMult(M, matrixPow(M, n - 1));
    return matrixPow(matrixMult(M, M), n / 2);
  }
};




/*
Algorithm Explanation:
1. Define a class `Solution` with a public method `lengthAfterTransformations`.
2. The method takes a string `s`, an integer `t`, and a vector of integers `nums` as input.
3. Define a constant `kMod` for modulo operations.
4. Define a private method `getTransformationMatrix` that takes a vector of integers `nums` and returns a transformation matrix.
5. Initialize a 2D vector `T` of size 26x26 to store the transformation matrix.
6. Iterate through the `nums` vector and fill the transformation matrix `T` based on the values in `nums`.
7. Define a private method `getIdentityMatrix` that takes an integer `sz` and returns an identity matrix of size `sz`.
8. Define a private method `matrixMult` that takes two 2D vectors `A` and `B` and returns their product modulo `kMod`.
9. Define a private method `matrixPow` that takes a 2D vector `M` and an integer `n` and returns the matrix `M` raised to the power of `n`.
10. If `n` is 0, return the identity matrix of size `M.size()`.
11. If `n` is odd, return the product of `M` and the result of `matrixPow(M, n - 1)`.
12. If `n` is even, return the result of `matrixPow(matrixMult(M, M), n / 2)`.
13. In the `lengthAfterTransformations` method, call `getTransformationMatrix` to get the transformation matrix `T`.
14. Call `matrixPow` to get the powered transformation matrix `poweredT`.
15. Initialize a vector `count` of size 26 to store the frequency of each character in the string `s`.
16. Initialize a vector `lengths` of size 26 to store the lengths of each character after transformations.
17. Iterate through each character in the string `s` and update the frequency in `count`.
18. Iterate through the `count` vector and update the `lengths` vector using the powered transformation matrix `poweredT`.
19. Use the `accumulate` function to sum up the lengths of all characters in the `lengths` vector.
20. Return the result modulo `kMod`.

*/