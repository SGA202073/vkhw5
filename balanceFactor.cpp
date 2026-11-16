int calculateHeightsAndBalance(TreeNode* node) 
{
    if (!node)
        return 0;
    int leftHeight = calculateHeightsAndBalance(node->left);
    int rightHeight = calculateHeightsAndBalance(node->right);
    node->balanceFactor = leftHeight - rightHeight;
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}
/* используем обход post-order (левый -> правый -> корень). сначала рекурсивно спускаемся до листьев.
на обратном пути мы уже знаем высоты левого и правого поддеревьев. записываем в узел баланс как leftHeight - rightHeight. сама высота текущего узла это 1 + max(left, right).
так мы за один проход вычисляем и высоту, и баланс */