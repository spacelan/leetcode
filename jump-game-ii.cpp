/** \link https://leetcode.com/problems/jump-game-ii/
 * \comment 这是别人的答案，写得非常简洁，用的贪心算法。一开始看到这个题我就想着用动态规划，实现也非常简单，结果超时。确实，用动规的搜索范围也很大，最坏情况下O(n^2)。所以我又想了各种办法剪枝，也不行。没办法，去讨论看到了这个答案，贪心算法，时间O(n)。其思路是迭代当前节点与当前节点所能跳到的最远节点之间的所有节点，找出再跳一次能到达的最远节点，跳到该节点，更新状态，继续迭代。最后，这次我深刻地认识到，千万不要不相信Tag标签给的提示，，说是贪心，那么，，还真的是用贪心。。。
 */
class Solution {
public:
    int jump(int A[], int n) {
        int i = 0, j = 1, cnt = 0, mx;
        if (n == 1) return 0;
        while (i < n - 1 && i + A[i] < n - 1) {
            for (mx = j; j <= i + A[i]; j++) {
                 mx = (mx + A[mx] <= j + A[j]) ? j : mx;
            }
            i = mx; cnt++;
        }
        return ++cnt;
    }
};


/*还是贴上我自己的动规代码*/
class Solution {
public:
    int jump(int A[], int n) {
        int jump_count[n];
        int index = n - 1;
        int i;
        memset(jump_count,0,n*sizeof(int));
        jump_count[0] = n - 1;
        while(index--){
            if(A[index] == 0) continue;
            i = 0;
            while(index+A[index]<jump_count[i])
                i++;
            if(jump_count[i] == 0) continue;
            jump_count[i+1] = index;
        }
        return i+1;
    }
}；
