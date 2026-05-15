/*
Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:
Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
All books must be allocated.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.
Note: If it is not possible to allocate books to all students, return -1.

Examples:
Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
=> [12] and [34, 67, 90] Maximum Pages = 191
=> [12, 34] and [67, 90] Maximum Pages = 157
=> [12, 34, 67] and [90] Maximum Pages = 113.
The third combination has the minimum pages assigned to a student which is 113.

Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.

Constraints:
1 ≤ arr.size() ≤ 10^6
1 ≤ arr[i], k ≤ 10^3

Time Complexity: O(n * log(sum(arr)))
Space Complexity: O(1)
*/

class Solution {
  public:
    int countStudents(vector<int> &arr, int pages){
        int students = 1;
        long long pagesStudent = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if(pagesStudent + arr[i] <= pages){
                pagesStudent += arr[i];
            }else{
                students++;
                pagesStudent = arr[i];
            }
        }
        return students;
    }
    int findPages(vector<int> &arr, int k) {
        if(k > arr.size()){
            return -1;
        }
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        while(low <= high){
            int mid = (low + high) / 2;
            int students = countStudents(arr, mid);
            if(students > k){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low;
    }
};
