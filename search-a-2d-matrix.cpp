/** \link https://leetcode.com/problems/search-a-2d-matrix/
 * \comments 水题
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int i;
        for(i=0;i<matrix.size();i++){
            if(target<matrix[i][0])
                break;
        }
        if(i==0) return false;
        return search_binary((matrix[i-1]).data(),0,(matrix[0]).size()-1,target);
    }
    bool search_binary(int *m, int i, int j, int &target){
        if(i>j) return false;
        int mid = i + (j - i) / 2;
        if(target == *(m+i)) return true;
        if(target == *(m+j)) return true;
        if(target == *(m+mid)) return true;
        if(target < *(m+mid)) return search_binary(m,i+1,mid-1,target);
        if(target > *(m+mid)) return search_binary(m,mid+1,j-1,target);
        return false;
    }
};
