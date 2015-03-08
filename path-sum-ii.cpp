/** \brief https://leetcode.com/problems/path-sum-ii/
 *comments 二叉树，深度优先搜索
 */
class Solution {
public:
    vector<vector<int> > result;
    vector<int> path;
    int s;
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if(root != NULL){
            s = sum;
            search(root, 0);
        }
        return result;
    }
    void search(TreeNode *node, int n){
        path.push_back(node->val);
        if(node->left == NULL && node->right == NULL){
            if(n + node->val == s) result.push_back(path);
        }
        else{
            if(node->left) search(node->left, n + node->val);
            if(node->right) search(node->right, n + node->val);
        }
        path.pop_back();
    }
};
