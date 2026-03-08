/*
A pangram is a sentence where every letter of the English alphabet appears at least once.
Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

 Example 1:
Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.
  
Example 2:
Input: sentence = "leetcode"
Output: false
 
Constraints:
1 <= sentence.length <= 1000
sentence consists of lowercase English letters.

Time Complexity: O(n)
Space Complexity: O(1)

*/

class Solution {
public:
    bool checkIfPangram(string s) {
        int n = s.length();
        if(n < 26){
            return false;
        }
        bool visited[26] = {false};
        for(int i = 0; i < n; i++){
            char x = s[i];
            if(x >= 'a' && x <= 'z'){
                visited[x - 'a'] = true;
            }
            if(x >= 'A' && x <= 'Z'){
                visited[x - 'A'] = true;
            }
        }
        for(int j = 0; j < 26; j++){
            if(visited[j] == false){
                return false;
            }
        }
        return true;
    }
};
