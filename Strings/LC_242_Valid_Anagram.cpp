/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:
1 <= s.length, t.length <= 5 * 10^4
s and t consist of lowercase English letters.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.length() != t.length()){
        return false;
       } 
       int freq[26] = {0};
       for(int i = 0; i < s.length(); i++){
        freq[s[i] - 'a']++;
       }
       for(int i = 0; i < t.length(); i++){
        freq[t[i] - 'a']--;
       }
       for(int i = 0; i < 26; i++){
        if(freq[i] != 0){
            return false;
        }
       }
       return true;
    }
};
