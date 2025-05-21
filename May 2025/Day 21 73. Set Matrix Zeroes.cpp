
/*
    Leetcode Problem 73 : Set Matrix Zeroes
    https://leetcode.com/problems/set-matrix-zeroes/

    Problem Explanation:

    Given an m x n matrix, if an element is 0, set its entire row and column to 0. Do this in-place (modify the original matrix).

    Approach :

    Find All Zeroes:

    Traverse the matrix and store the positions of all zero elements in a queue.
    Set Rows and Columns to Zero:

    For each zero position, set all elements in its row and column to zero.
    Steps in Code
    Loop through the matrix to find all zeroes and store their positions.
    For each stored zero position, set the corresponding row and column to zero.

    Time Complexity:
    Finding all zeroes: O(m * n)
    For each zero, setting its row and column: O(m + n) per zero
    In the worst case (all elements are zero), this can be O((m + n) * (m * n)).

    Space Complexity:
    O(k), where k is the number of zeroes (for the queue).
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        queue<pair<int, int>> zeroque; // Queue to store positions of zeroes
        // Find all zeroes and store their positions
        for(int i=0; i<m; i++){ 
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0) zeroque.push({i, j});
            }
        }

        while(!zeroque.empty()){ // For each zero position
            // Get the position of the zero
            int x = zeroque.front().first;
            int y = zeroque.front().second;
            zeroque.pop();

            // for column
            for(int i=0; i<n; i++){
                matrix[x][i] = 0;
            }

            // for row
            for(int i=0; i<m; i++){
                matrix[i][y] = 0;
            }
        }
    }
};