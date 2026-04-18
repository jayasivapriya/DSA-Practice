/*
You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then return -1.

Examples :
Input: n = 3, m = 8
Output: 2
Explanation: 23 = 8

Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not integer.

Input: n = 4, m = 16
Output: 2
Explanation: 24 = 16

Constraints:
1 ≤ n ≤ 9
0 ≤ m ≤ 20

Time Complexity: O(n log m)
Space Complexity: O(1)
*/

class Solution {
  public:
    int func(int mid, int n, int m){
        long long ans = 1;
        for(int i = 1; i <= n; i++){
            ans *= mid;
            if(ans > m){
                return 2;
            }
        }
        if(ans == m){
            return 1;
        }
        return 0;
    }
    int nthRoot(int n, int m) {
        int low = 1, high = m;
        if(m == 0){
            return 0;
        }
        while(low <= high){
            int mid = low + (high - low) / 2;
            int midN = func(mid, n, m);
            if(midN == 1){
                return mid;
            }else if(midN == 0){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return -1;
    }
};
