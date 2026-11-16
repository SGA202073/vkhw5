bool isCompleteTree(TreeNode* root)
{
    if(!root)
        return true;
    TreeNode* queue[1000];
    int head = 0;
    int tail = 0;
    queue[tail++] = root;
    bool seenNull = false;
    while (head < tail)
    {
        TreeNode* node = queue[head++];
        if (!node)
            seenNull = true;
        else
        {
            if(seenNull)
                return false;
            queue[tail++] = node->left;
            queue[tail++] = node->right;
        }
    }
    return true;
}
/* используем обход в ширину (BFS) с очередью. идем по уровням и проверяем условие заполненности: как только встретили пустой узел, ставим флаг seenNull;
если после этого встретили реальный узел, значит образовалась дыра и дерево не полное. BFS подходит лучше всего, так как мы проверяем узлы в том порядке, в котором они должны заполняться (сверху вниз и слева направо) */