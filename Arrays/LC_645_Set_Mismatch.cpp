/*
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to 
another number in the set, which results in repetition of one number and loss of another number.
You are given an integer array nums representing the data status of this set after the error.
Find the number that occurs twice and the number that is missing and return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]

Example 2:
Input: nums = [1,1]
Output: [1,2]
 
Constraints:
2 <= nums.length <= 10^4
1 <= nums[i] <= 10^4

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();
        long long sum = (n * (n + 1)) / 2;
        long long sqSum = (n * ( n + 1) * (2 * n + 1)) / 6;
        long long numsSum = 0, numsSqSum = 0;
        for(int i = 0; i < n; i++){
            numsSum += nums[i];
            numsSqSum += (long long)nums[i] * (long long)nums[i];
        }
        long long val1 = sum - numsSum;
        long long val2 = sqSum - numsSqSum;
        val2 = val2 / val1;
        long long x = (val1 + val2) / 2;
        long long y = x - val1;
        return {(int)y, (int)x};
    }
};
