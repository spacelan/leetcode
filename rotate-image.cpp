/** \link https://oj.leetcode.com/problems/rotate-image/
 * \comments 用了in-place algorithm，没有增加额外空间，但是处理速度有下降。这个题没有涉及高级算法，但是需要逻辑清晰，并熟悉线性代数相关知识。与计算机图形学相关。
 *
 */   
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for(int i=0;i<(n+1)/2;i++){
            int x = i,y = i;
            int last = matrix[x][y];
            for(int k=0;k<n-1-2*i;k++){
                for(int j=0;j<4;j++){
                    int tmp = x;
                    x = y;
                    y = -tmp + n - 1;
                    tmp = matrix[x][y];
                    matrix[x][y] = last;
                    last = tmp;
                }
                y++;
                last = matrix[x][y];
            }
        }
    }
};
