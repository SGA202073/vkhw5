struct TreeNode 
{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val = 0, TreeNode* left = nullptr, TreeNode* right = nullptr) : value(val), left(left), right(right) { }
};
TreeNode* buildTree(int* arr, int arrLength, int i = 0) 
{
    if (i >= arrLength)
        return nullptr;
    TreeNode* root = new TreeNode(arr[i]);
    root->left = buildTree(arr, arrLength, 2 * i + 1);
    root->right = buildTree(arr, arrLength, 2 * i + 2);
    return root;
}
TreeNode* inorderMin(TreeNode* node, int k, int& counter) 
{
    if (node == nullptr)
        return nullptr;
    TreeNode* leftResult = inorderMin(node->left, k, counter);
    if (leftResult != nullptr)
        return leftResult;
    counter++;
    if (counter == k)
        return node;
    return inorderMin(node->right, k, counter);
}
int findKthSmallest(TreeNode* root, int k) 
{
    int counter = 0;
    TreeNode* result = inorderMin(root, k, counter);
    if (result != nullptr)
        return result->value; 
    return -1;
}
/* используем обход lnr. в bst такой обход выдает элементы строго по возрастанию.
идем рекурсивно в самое левое поддерево, при посещении узла увеличиваем счетчик. если счетчик = k, значит это наш элемент, возвращаем его.
 если слева уже нашли ответ, сразу возвращаем наверх, иначе идем вправо. сложность O(H+K) по времени и O(H) по памяти на стек рекурсии */