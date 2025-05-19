class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        
        int n = words.size();
        vector<string> ans; // to store the longest subsequence

        int flag = groups[0]; // to store the first group
        ans.push_back(words[0]);// push the first word to the answer

        for(int i=1; i<n; i++){ // iterate through the words
            // if the group of the current word is not equal to the previous group
            if(flag != groups[i]){ 
                ans.push_back(words[i]); // push the current word to the answer
                flag = groups[i]; // update the group
            }
        }
        return ans;
    }
};


// Time Complexity: O(n)
// Space Complexity: O(1)