TreeNode* mirrorTreeIterative(TreeNode* root) 
{
    if (!root)
        return nullptr;
    TreeNode* queue[10000];
    int head = 0;
    int tail = 0;
    queue[tail++] = root;
    while (head < tail) 
    {
        TreeNode* current = queue[head++];
        TreeNode* temp = current->left;
        current->left = current->right;
        current->right = temp;
        if (current->left)
            queue[tail++] = current->left;
        if (current->right)
            queue[tail++] = current->right;
    }
    return root;
}
/* алгоритм корректен, потому что мы проходим по всем узлам без исключения и на каждом шаге просто меняем местами указатели left и right.
если сделать это для всех узлов, левое поддерево станет правым и наоборот. используем BFS с очередью. сложность O(N) по времени, так как каждый узел обрабатывается один раз, память O(N) для очереди */