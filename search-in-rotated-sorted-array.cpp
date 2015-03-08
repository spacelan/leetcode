/** \link https://oj.leetcode.com/problems/search-in-rotated-sorted-array/
 *
 * \comments 二分查找。由于数组进行过旋转，所以要确认当前子串是否为顺序子串
 * \param 
 * \return 
class Solution {
public:
    int search(int A[], int n, int target) {
        return work(A, 0, n - 1, target);
    }
    int work(int A[], int b, int e, int target){
        if(b > e) return -1;
        if(target == A[b]) return b;
        if(target == A[e]) return e;
        int mid = b + (e - b) / 2;
        if(target == A[mid]) return mid;
        if(A[b] < A[mid]){
            if(target > A[b] && target < A[mid]) return work(A, b + 1, mid - 1, target);
            return work(A, mid + 1, e - 1, target);
        }
        else{
            if(target > A[mid] && target < A[e]) return work(A, mid + 1, e - 1, target);
            return work(A, b + 1, mid - 1, target);
        }
    }
};
