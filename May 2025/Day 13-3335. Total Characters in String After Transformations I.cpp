/*
Problem:
This code solves the problem of finding the total number of characters in a string after t transformations, where each transformation is defined as follows:

For each character in the string:
If the character is 'z', it is replaced by 'a' and 'b' (so its count is split into both).
Otherwise, the character is replaced by the next character in the alphabet (e.g., 'a' becomes 'b').
Step-by-step Approach
Count Initial Frequencies:
The code first counts the frequency of each character in the input string s using a vector mp of size 26 (for each lowercase letter).

Apply Transformations:
For t times, it performs the transformation:

For each character (from 'a' to 'z'):
If the character is 'z', its count is added to both 'a' and 'b' in the new frequency vector.
Otherwise, its count is added to the next character in the alphabet.
After processing all characters, the new frequency vector becomes the current one for the next iteration.
Sum the Result:
After all transformations, sum up the counts of all characters to get the final answer.

*/

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        
        int n = s.length();
        vector<int> mp(26, 0);
        const int M = 1e9+7;

        for(char ch : s){ // Count frequency of each character
            mp[ch-'a']++;
        }

        while(t--){ // Perform transformations
            // Create a new frequency vector for the next transformation
            vector<int> curr(26, 0);
            for(int i=0; i<26; i++){ // Iterate through each character
                char ch = i + 'a';
                int freq = mp[i];
                if(ch == 'z'){
                    curr[0] = (curr[0] + freq)%M;
                    curr[1] = (curr[1]+freq)%M;
                }else curr[ch+1-'a'] = (curr[ch+1-'a']+freq)%M;
            }
            mp = move(curr);
        }

        int count = 0;
        for(int i=0; i<26; i++){
            count = (count + mp[i])%M;
        }

        return count;
    }
};


/*
Complexity Analysis
Time Complexity
Counting initial frequencies: O(n), where n is the length of the string.
Transformations:
Each transformation iterates over 26 characters, and there are t transformations.
So, total time for transformations: O(26 * t) = O(t).
Summing the result: O(26) = O(1).
Overall Time Complexity:
O(n + t)

Efficient for small t (up to 1e5 or so), but not suitable for very large t (e.g., 1e9).
Space Complexity
Uses two vectors of size 26: O(1) (constant space, since 26 is fixed).
*/