/*
Leetcode Problem 3355: Zero Array Transformation I
https://leetcode.com/problems/zero-array-transformation-i/

Problem Explanation
This problem is based on transforming an array to all zeros using a series of range queries.

Given:
An integer array nums.
A list of queries, where each query is a pair [left, right] representing a range of indices in nums.
Operation:
For each query [left, right], you can decrease every element in nums from index left to right by 1 (but not below zero).

Goal:
After performing all queries in order, check if all elements in nums are zero.

Example:
Suppose nums = [2, 1, 1] and [queries = [[0, 1], [1, 2]]]:

First query: decrease nums[0] and nums[1] by 1 → [1, 0, 1]
Second query: decrease nums[1] and nums[2] by 1 → [1, 0, 0]
Not all elements are zero, so return false.

**Brute Force Approach:**

Approach:
The first implementation simulates each query directly by decrementing the specified range.
The second implementation uses a difference array to efficiently count how many times each index will be decremented, then checks if each nums[i] can be reduced to zero or less.


Time Complexity: O(n * m)
O(n * m) for the brute force approach, where n is the number of queries and m is the size of nums.

Space Complexity: O(1)
O(1) for the brute force approach, as we are not using any extra space apart from the input array.
*/

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = queries.size();

        for(int i=0; i<n; i++){
            int left = queries[i][0];
            int right = queries[i][1];

            for(int j=left; j<=right; j++){
                if(nums[j] == 0) continue;
                nums[j]--;
            }
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);

        return (sum==0) ? true : false;
    }
};

/*

Optimal Approach:
The second implementation uses a difference array to efficiently count how many times each index will be decremented.
Time Complexity: O(n + m)
Space Complexity: O(m)

Approach:
1. Create a difference array of the same size as nums, initialized to 0.
2. For each query [left, right], increment the left index in the difference array and decrement the right+1 index (if within bounds).
3. Compute the cumulative sum of the difference array to get the final decrements for each index.
4. Check if each nums[i] is greater than the corresponding value in the difference array.

*/



class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int n = queries.size();
        int m = nums.size();
        vector<int> diffArray(m, 0); // difference array

        for(int i=0; i<n; i++){ 
            int left = queries[i][0]; // left index of the query
            int right = queries[i][1]+1; // right index of the query
            
            diffArray[left] += 1; // increment the left index
            if(right < m) diffArray[right] -= 1; // decrement the right+1 index
        }

        // for commulative sum
        for(int i=1; i<m; i++){
            diffArray[i] += diffArray[i-1]; // cumulative sum
        }

        for(int i=0; i<m; i++){

            // check if nums[i] is greater than the corresponding value in the difference array
            if(nums[i] > diffArray[i]) return false;  
        }

        return true;
    }
};