/*
Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 
Constraints:
-2^31 <= x <= 2^31 - 1

Time Complexity: O(log10(x))
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPalindrome(int x) {
        int n = x;
        long long revnum = 0;
        if(n < 0)
        return false;
        while(n>0){
            int lastdigit = n % 10;
            n /= 10;
            revnum = (revnum * 10) + lastdigit;
            if(revnum > INT_MAX || revnum < INT_MIN)
            return false;
        }
        return revnum == x ? true : false;
    }
};
