/** \link NULL
 * \comments 总结一下二叉树的非递归遍历
 */

struct Node
{
    int value;
    struct Node *left, *right;
    Node(int x): value(x), left(NULL), right(NULL) {}
};

//最简单的先序遍历
void preOrder(Node *tree_node)
{
    Node *p = NULL;
    stack<Node*> nodes;
    nodes.push(tree_node);
    while(!nodes.empty())
    {
        p = nodes.top();
        nodes.pop();
        cout<<p->value<<endl;
        if(p->right != NULL)
            nodes.push(p->right);
        if(p->left != NULL)
            nodes.push(p->left);
    }
}

void inOrder(Node *tree_node)
{
    Node *p = tree_node;
    stack<Node*> nodes;
    while(p != NULL || !nodes.empty())
    {
        while(p != NULL)
        {
            nodes.push(p);
            p = p->left;
        }
        if(!nodes.empty())
        {
            p = nodes.top();
            nodes.pop();
            cout<<p->value<endl;
            p = p->right;
        }
    }
}

//最复杂的后序遍历，但是这个方法同样可以解决先序和中序
void postOrder(Node *tree_node)
{
    Node *p = tree_node;
    bool visited;
    stack<pair<Node*, bool> > nodes;
    nodes.push(make_pair(tree_node, false));
    while(!nodes.empty())
    {
        p = nodes.top().first;
        visited = node.top().second;
        nodes.pop();
        if(p != NULL)
        {
            if(visited == true)
            {
                cout<<p->value<<endl;
            }
            else
            {
                nodes.push(make_pair(p, true));
                nodes.push(make_pair(p->right, false));
                nodes.push(make_pair(p->left, false));
            }
        }
    }
}
