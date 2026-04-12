/*
Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 

Examples :
Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
Output: 4
Explanation: target = 2 occurs 4 times in the given array so the output is 4.

Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
Output: 0
Explanation: target = 4 is not present in the given array so the output is 0.

Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
Output: 3
Explanation: target = 12 occurs 3 times in the given array so the output is 3.

Constraints:
1 ≤ arr.size() ≤ 10^6
1 ≤ arr[i] ≤ 10^6
1 ≤ target ≤ 10^6

Time Complexity: O(2 * log n)
Space Complexity: O(1)
*/

class Solution {
  public:
    int firstOccurence(vector<int>& arr, int k){
        int n = arr.size();
        int low = 0, high = n - 1, first = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(arr[mid] == k){
                first = mid;
                high = mid - 1;
            }else if(arr[mid] < k){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return first;
    }
    int lastOccurence(vector<int>& arr, int k){
        int n = arr.size();
        int low = 0, high = n - 1, last = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(arr[mid] == k){
                last = mid;
                low = mid + 1;
            }else if(arr[mid] < k){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return last;
    }
    pair<int, int> firstAndLastPosition(vector<int>& arr, int target){
        int first = firstOccurence(arr, target);
        if(first == -1){
            return {-1, -1};
        }
        int last = lastOccurence(arr, target);
        return {first, last};
    }
    int countFreq(vector<int>& arr, int target) {
        pair<int, int> ans = firstAndLastPosition(arr, target);
        if(ans.first == -1){
            return 0;
        }
        return ans.second - ans.first + 1;
    }
};
