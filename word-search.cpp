/** \link https://oj.leetcode.com/problems/word-search/
 * \comments 回溯法。还是要注意熟悉STL模板的用法，真是一点都不熟练啊
 */
class Solution {
public:
    int n,m;
    vector<vector<char> > *b;
    string *w;
    bool exist(vector<vector<char> > &board, string word) {
        n = board.size();
        m = board[0].size();
        b = &board;
        w = &word;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0])
                    if(work(i, j, 0)) return true;
            }
        }
        return false;
    }
    bool work(int i, int j, int index){
        if(index == w->length() - 1) return true;
        char ch = (*w)[index];
        (*b)[i][j] = 0;
        if(i > 0 && (*b)[i-1][j] == (*w)[index + 1])
            if(work(i - 1, j, index + 1)) return true;
        if(i < n - 1 && (*b)[i+1][j] == (*w)[index + 1])
            if(work(i + 1, j, index + 1)) return true;
        if(j > 0 && (*b)[i][j-1] == (*w)[index + 1])
            if(work(i, j - 1, index + 1)) return true;
        if(j < m - 1 && (*b)[i][j+1] == (*w)[index + 1])
            if(work(i, j + 1, index + 1)) return true;
        (*b)[i][j] = ch;
        return false;
    }
};
