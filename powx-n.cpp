/** \link https://oj.leetcode.com/problems/powx-n/
 * \comments 二分法。注意最小的32位有符号整型-2147483648需特别考虑，|-2147483648|=2147483648---32位有符号整型溢出--->-2147483648。参考补码和二进制数据存储方面知识。
 */     
class Solution {
public:
    double pow(double x, int n) {
        if(x == 0) return 0;
        if(n == -2147483648) return 1/(pow(x,-(n+1))*x);
        if(n<0) return 1/pow(x,n*-1);
        if(n == 0) return 1;
        double result = pow(x,n/2);
        return result*result*(n%2 == 1?x:1);
    }
};
