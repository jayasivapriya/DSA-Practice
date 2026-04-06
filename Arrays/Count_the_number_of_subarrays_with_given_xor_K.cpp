/*
Problem Statement: Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k.
Input: A = [4, 2, 2, 6, 4] , k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
Input: A = [5, 6, 7, 8, 9], k = 5
Output: 2
Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

int subarrayWithSumK(vector<int> a, int k){
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;
    int count = 0;
    for(int i = 0; i < a.size(); i++){
        xr = xr ^ a[i];
        int x = xr ^ k;
        count += mpp[x];
        mpp[xr]++;
    }
    return count;
}
