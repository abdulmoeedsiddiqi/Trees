// Given a binary tree, determine if it is height-balanced. 
// A binary tree is considered height-balanced if the absolute difference in 
// heights of the left and right subtrees is at most 1 for every node in the tree.



bool isBalanced(Node* root) {
    if (root == NULL) return true; // An empty tree is balanced

    // Recursively check if the left and right subtrees are balanced
    bool leftBalanced = isBalanced(root->left);
    bool rightBalanced = isBalanced(root->right);

    // Calculate the height difference of the left and right subtrees
    int heightDiff = abs(height(root->left) - height(root->right));

    // Check if current node is balanced
    bool currentBalanced = heightDiff <= 1;

    // If left, right, and current node are balanced, return true
    return leftBalanced && rightBalanced && currentBalanced;
}
