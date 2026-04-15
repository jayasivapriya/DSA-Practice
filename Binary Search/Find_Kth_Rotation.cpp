/*
Given an increasing sorted rotated array arr[] of distinct integers. The array is right-rotated k times. Find the value of k.
Let's suppose we have an array arr[] = [2, 4, 6, 9], if we rotate it by 2 times it will look like this:
After 1st Rotation : [9, 2, 4, 6]
After 2nd Rotation : [6, 9, 2, 4]

Examples:
Input: arr[] = [5, 1, 2, 3, 4]
Output: 1
Explanation: The given array is [5, 1, 2, 3, 4]. The original sorted array is [1, 2, 3, 4, 5]. We can see that the array was rotated 1 times to the right.

Input: arr = [1, 2, 3, 4, 5]
Output: 0
Explanation: The given array is not rotated.

Constraints:
1 ≤ arr.size() ≤ 10^5
1 ≤ arr[i] ≤ 10^7

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int low = 0, high = arr.size() - 1;
        int ans = INT_MAX, index = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(arr[low] <= arr[high]){
                if(arr[low] < ans){
                    ans = arr[low];
                    index = low;
                }
                break;
            }
            if(arr[low] <= arr[mid]){
                if(arr[low] < ans){
                    ans = arr[low];
                    index = low;
                }
                low = mid + 1;
            }else{
                if(arr[mid] < ans){
                    ans = arr[mid];
                    index = mid;
                }
                high = mid - 1;
            }
        }
        return index;
    }
};
