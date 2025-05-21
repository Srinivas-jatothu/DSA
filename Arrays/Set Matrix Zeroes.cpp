// leetcode problem : https://leetcode.com/problems/set-matrix-zeroes/description/?envType=daily-question&envId=2025-05-21

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m =  matrix.size();
        int n= matrix[0].size();

        vector<vector<int>> temp = matrix;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<n;k++){
                        temp[i][k]=0;
                    }
                    for(int k=0;k<m;k++){
                        temp[k][j]=0;
                    }
                }
            }
        }

        matrix=temp;

    }
};

/*
Algortihm explanation:
1. Get the number of rows (m) and columns (n) in the matrix.
2. Create a temporary matrix (temp) to store the modified values.
3. Iterate through each element of the original matrix.
4. If an element is zero, set the entire row and column in the temporary matrix to zero.
5. After processing all elements, copy the temporary matrix back to the original matrix.
6. The final matrix will have all rows and columns set to zero where there was at least one zero in the original matrix.
7. The time complexity is O(m*n) and the space complexity is O(m*n) due to the temporary matrix.
8. This approach ensures that the original matrix is not modified while checking for zeros, preventing premature zeroing of rows and columns.

*/