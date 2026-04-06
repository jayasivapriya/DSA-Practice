/*
Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

Example 1:
Input:
 N = 6, array[] = {9, -3, 3, -1, 6, -5}  
Result:
 5  
Explanation:
 The following subarrays sum to zero:
- {-3, 3}
- {-1, 6, -5}
- {-3, 3, -1, 6, -5}
The length of the longest subarray with sum zero is 5.

Example 2:
Input:
 N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10}  
Result:
 8  
Explanation:
 Subarrays with sum zero:
- {-2, 2}
- {-8, 1, 7}
- {-2, 2, -8, 1, 7}
- {6, -2, 2, -8, 1, 7, 4, -10}
The length of the longest subarray with sum zero is 8.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/
int maxLen(int arr[], int n){
    unordered_map<int, int> mpp;
    int sum = 0, maxi = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum == 0){
            maxi = i + 1;
        }else{
            if(mpp.find(sum) != mpp.end()){
                maxi = max(maxi, i - mpp[sum]);
            }else{
                mpp[sum] = i;
            }
        }
    }
    return maxi;
}

