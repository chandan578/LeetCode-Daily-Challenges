// Leetcode 3024. Type of Triangle
// https://leetcode.com/problems/type-of-triangle/

/*
Given:
An array nums of three integers, each representing the length of a side of a triangle.

Task:
Determine the type of triangle these sides form:

"equilateral": All three sides are equal.
"isosceles": Exactly two sides are equal.
"scalene": All sides are different.
"none": The sides do not form a valid triangle (i.e., the triangle inequality does not hold).
Triangle Inequality:
For any triangle with sides a, b, c:

a + b > c
a + c > b
b + c > a
If any of these fail, the sides do not form a triangle.
*/
class Solution {
public:
    string triangleType(vector<int>& nums) {
        
        if(nums[0] == nums[1] && nums[1] == nums[2]) return "equilateral";
        if((nums[0]+nums[1]<=nums[2]) ||
            (nums[0]+nums[2]<=nums[1]) ||
            (nums[1]+nums[2]<=nums[0]))  return "none";
        if((nums[0]==nums[1]) || (nums[1]==nums[2]) || (nums[0]==nums[2])) return "isosceles";
        return "scalene";
    }
};

/*
Time Complexity
The function performs a constant number of comparisons and additions (no loops).
Time Complexity: O(1) (constant time)
Space Complexity: O(1) (constant space)
*/